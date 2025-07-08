#include <stdio.h>
#include <spine-c.h>

int main() {
    printf("Testing spine-c-new...\n");
    
    // Test version functions
    printf("Spine version: %d.%d\n", spine_major_version(), spine_minor_version());
    
    // Test debug extension
    spine_enable_debug_extension(1);
    
    // Test creating bounds
    spine_bounds bounds = (spine_bounds)malloc(sizeof(struct spine_bounds_wrapper));
    if (bounds) {
        printf("Successfully created bounds\n");
        free(bounds);
    }
    
    // Report any memory leaks
    spine_report_leaks();
    
    return 0;
}