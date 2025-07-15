#include "atlas_attachment_loader.h"
#include <spine/spine.h>

using namespace spine;

spine_atlas_attachment_loader spine_atlas_attachment_loader_create(spine_atlas atlas) {
    return (spine_atlas_attachment_loader) new (__FILE__, __LINE__) AtlasAttachmentLoader((Atlas *)atlas);
}

void spine_atlas_attachment_loader_dispose(spine_atlas_attachment_loader self) {
    delete (AtlasAttachmentLoader*)self;
}

spine_region_attachment spine_atlas_attachment_loader_new_region_attachment(spine_atlas_attachment_loader self, spine_skin skin, const char * name, const char * path, spine_sequence sequence) {
    return (spine_region_attachment)((AtlasAttachmentLoader*)self)->newRegionAttachment(*((Skin*)skin), String(name), String(path), (Sequence *)sequence);
}

spine_mesh_attachment spine_atlas_attachment_loader_new_mesh_attachment(spine_atlas_attachment_loader self, spine_skin skin, const char * name, const char * path, spine_sequence sequence) {
    return (spine_mesh_attachment)((AtlasAttachmentLoader*)self)->newMeshAttachment(*((Skin*)skin), String(name), String(path), (Sequence *)sequence);
}

spine_bounding_box_attachment spine_atlas_attachment_loader_new_bounding_box_attachment(spine_atlas_attachment_loader self, spine_skin skin, const char * name) {
    return (spine_bounding_box_attachment)((AtlasAttachmentLoader*)self)->newBoundingBoxAttachment(*((Skin*)skin), String(name));
}

spine_path_attachment spine_atlas_attachment_loader_new_path_attachment(spine_atlas_attachment_loader self, spine_skin skin, const char * name) {
    return (spine_path_attachment)((AtlasAttachmentLoader*)self)->newPathAttachment(*((Skin*)skin), String(name));
}

spine_point_attachment spine_atlas_attachment_loader_new_point_attachment(spine_atlas_attachment_loader self, spine_skin skin, const char * name) {
    return (spine_point_attachment)((AtlasAttachmentLoader*)self)->newPointAttachment(*((Skin*)skin), String(name));
}

spine_clipping_attachment spine_atlas_attachment_loader_new_clipping_attachment(spine_atlas_attachment_loader self, spine_skin skin, const char * name) {
    return (spine_clipping_attachment)((AtlasAttachmentLoader*)self)->newClippingAttachment(*((Skin*)skin), String(name));
}

spine_atlas_region spine_atlas_attachment_loader_find_region(spine_atlas_attachment_loader self, const char * name) {
    return (spine_atlas_region)((AtlasAttachmentLoader*)self)->findRegion(String(name));
}
