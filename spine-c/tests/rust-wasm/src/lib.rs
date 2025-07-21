use std::ffi::{CStr, CString};
use std::os::raw::{c_char, c_float, c_int, c_void};

// Opaque pointer types matching spine-c - all are SPINE_OPAQUE_TYPE which means pointers
type SpineAtlas = *mut c_void;
type SpineSkeletonData = *mut c_void;
type SpineSkeleton = *mut c_void;
type SpineSkeletonDataResult = *mut c_void; // This is also an opaque pointer!

// FFI bindings to spine-c API (minimal subset for testing)
extern "C" {
    fn spine_bone_set_y_down(yDown: bool);
    fn spine_atlas_load_callback(
        data: *const c_char,
        atlasPath: *const c_char,
        textureLoader: extern "C" fn(*const c_char) -> *mut c_void,
        textureUnloader: extern "C" fn(*mut c_void) -> (),
    ) -> SpineAtlas;
    fn spine_atlas_dispose(atlas: SpineAtlas);
    fn spine_skeleton_data_load_binary(
        atlas: SpineAtlas,
        data: *const u8,
        length: i32,
        skeletonPath: *const c_char,
    ) -> SpineSkeletonDataResult;
    fn spine_skeleton_data_result_get_data(result: SpineSkeletonDataResult) -> SpineSkeletonData;
    fn spine_skeleton_data_result_get_error(result: SpineSkeletonDataResult) -> *const c_char;
    fn spine_skeleton_data_result_dispose(result: SpineSkeletonDataResult);
    fn spine_skeleton_create(skeletonData: SpineSkeletonData) -> SpineSkeleton;
    fn spine_skeleton_dispose(skeleton: SpineSkeleton);
    fn spine_skeleton_setup_pose(skeleton: SpineSkeleton);
    fn spine_skeleton_update_world_transform_1(skeleton: SpineSkeleton, physics: c_int);
    fn spine_skeleton_get_x(skeleton: SpineSkeleton) -> c_float;
    fn spine_skeleton_get_y(skeleton: SpineSkeleton) -> c_float;
}

// Headless texture loader functions with debug prints
extern "C" fn headless_texture_loader(path: *const c_char) -> *mut c_void {
    unsafe {
        let path_str = if !path.is_null() {
            CStr::from_ptr(path).to_string_lossy()
        } else {
            "NULL".into()
        };
        println!("DEBUG: texture_loader called with path: {}", path_str);
        
        let ptr = std::alloc::alloc(std::alloc::Layout::from_size_align(8, 8).unwrap());
        println!("DEBUG: texture_loader returning: {:?}", ptr);
        ptr as *mut c_void
    }
}

extern "C" fn headless_texture_unloader(texture: *mut c_void) -> () {
    println!("DEBUG: texture_unloader called with texture: {:?}", texture);
    
    if !texture.is_null() && texture as usize > 1 {
        unsafe {
            println!("DEBUG: deallocating texture: {:?}", texture);
            std::alloc::dealloc(texture as *mut u8, std::alloc::Layout::from_size_align(8, 8).unwrap());
            println!("DEBUG: texture deallocation completed");
        }
    } else {
        println!("DEBUG: skipping deallocation (null or invalid pointer)");
    }
    println!("DEBUG: texture_unloader returning");
}

#[no_mangle]
pub extern "C" fn test_spine_basic() -> c_int {
    unsafe {
        println!("Starting spine test...");
        spine_bone_set_y_down(false);
        println!("Set y_down...");

        // Load real spineboy atlas data
        let atlas_file = std::fs::read_to_string("../../../examples/spineboy/export/spineboy-pma.atlas")
            .expect("Failed to read atlas file");
        let atlas_data = CString::new(atlas_file).unwrap();
        let atlas_dir = CString::new("../../../examples/spineboy/export/").unwrap();
        
        println!("About to load atlas...");
        let atlas = spine_atlas_load_callback(
            atlas_data.as_ptr(),
            atlas_dir.as_ptr(),
            headless_texture_loader,
            headless_texture_unloader,
        );
        println!("Atlas loaded: {:?}", atlas);

        if atlas.is_null() {
            println!("Atlas is null!");
            return 1; // Failed to load atlas
        }

        // Load real spineboy skeleton data (binary format like the C test)
        println!("Reading skeleton file...");
        let skeleton_file = std::fs::read("../../../examples/spineboy/export/spineboy-pro.skel")
            .expect("Failed to read skeleton file");
        println!("Skeleton file size: {} bytes", skeleton_file.len());
        let skeleton_path = CString::new("../../../examples/spineboy/export/spineboy-pro.skel").unwrap();

        println!("About to call spine_skeleton_data_load_binary...");
        let result = spine_skeleton_data_load_binary(atlas, skeleton_file.as_ptr(), skeleton_file.len() as i32, skeleton_path.as_ptr());
        println!("spine_skeleton_data_load_binary returned: {:?}", result);
        
        if result.is_null() {
            println!("Result is null!");
            return 2;
        }
        
        println!("About to call spine_skeleton_data_result_get_data...");
        println!("Result pointer: {:?}", result);
        println!("Result is null: {}", result.is_null());
        
        // Try to read the error first to see if result is valid
        println!("Checking if result has error...");
        let error_ptr = spine_skeleton_data_result_get_error(result);
        println!("Error check completed. Error ptr: {:?}", error_ptr);
        
        if !error_ptr.is_null() {
            let error_str = CStr::from_ptr(error_ptr);
            println!("Found error: {:?}", error_str);
            spine_skeleton_data_result_dispose(result);
            spine_atlas_dispose(atlas);
            return 2;
        }
        
        println!("No error found, getting skeleton data...");
        let skeleton_data = spine_skeleton_data_result_get_data(result);
        
        if skeleton_data.is_null() {
            let error = spine_skeleton_data_result_get_error(result);
            if !error.is_null() {
                let error_str = CStr::from_ptr(error);
                eprintln!("Skeleton data error: {:?}", error_str);
            }
            spine_skeleton_data_result_dispose(result);
            spine_atlas_dispose(atlas);
            return 2; // Failed to load skeleton data
        }

        println!("Skeleton data is valid: {:?}", skeleton_data);
        // Test skeleton creation immediately 
        println!("Creating skeleton...");
        let skeleton = spine_skeleton_create(skeleton_data);
        println!("Skeleton create returned: {:?}", skeleton);
        if skeleton.is_null() {
            spine_skeleton_data_result_dispose(result);
            spine_atlas_dispose(atlas);
            return 3; // Failed to create skeleton
        }

        // Test basic operations
        println!("Calling spine_skeleton_setup_pose...");
        spine_skeleton_setup_pose(skeleton);
        println!("Setup pose completed");
        
        println!("Calling spine_skeleton_update_world_transform_1...");
        spine_skeleton_update_world_transform_1(skeleton, 1); // SPINE_PHYSICS_UPDATE = 1
        println!("Update world transform completed");

        println!("Getting skeleton position...");
        let x = spine_skeleton_get_x(skeleton);
        println!("Got x: {}", x);
        let y = spine_skeleton_get_y(skeleton);
        println!("Got y: {}", y);

        // Cleanup
        println!("Disposing skeleton...");
        spine_skeleton_dispose(skeleton);
        println!("Skeleton disposed");
        
        println!("Disposing skeleton data result...");
        spine_skeleton_data_result_dispose(result);
        println!("Skeleton data result disposed");
        
        // Test atlas disposal to get proper crash backtrace
        println!("About to call spine_atlas_dispose - crash expected...");
        spine_atlas_dispose(atlas);
        println!("Atlas disposal completed successfully");

        // Verify we got reasonable values
        println!("Verifying values...");
        if x.is_finite() && y.is_finite() {
            println!("SUCCESS! Test completed successfully");
            0 // Success
        } else {
            println!("FAILED! Invalid values");
            4 // Invalid values
        }
    }
}

// WASM export for web testing
#[cfg(target_arch = "wasm32")]
mod wasm {
    use super::*;
    use std::os::raw::c_int;

    #[no_mangle]
    pub extern "C" fn run_spine_test() -> c_int {
        test_spine_basic()
    }
}

// mod bindgen_test; // Temporarily disabled

#[cfg(test)]
mod tests {
    use super::*;
    // use crate::bindgen_test::*;

    #[test]
    fn test_spine_basic_works() {
        let result = test_spine_basic();
        assert_eq!(result, 0, "Spine basic test should succeed");
    }
    
    // #[test]
    // fn test_bindgen_version() {
    //     let result = test_bindgen_spine();
    //     assert_eq!(result, 0, "Bindgen test should succeed");
    // }
}