#include <stdio.h>
#include <stdlib.h>
#include <spine-c.h>

int main(int argc, char *argv[]) {
    printf("Testing spine-c-new...\n");

    // Test version functions
    printf("Spine version: %d.%d\n", spine_major_version(), spine_minor_version());

    // Test debug extension
    spine_enable_debug_extension(1);

    // Test loading an atlas (will fail but tests the API)
    spine_atlas atlas = spine_atlas_load("test.atlas");
    if (!atlas) {
        printf("Failed to load atlas (expected)\n");
    } else {
        spine_atlas_dispose(atlas);
    }

    // Report any memory leaks
    spine_report_leaks();

    return 0;
}
