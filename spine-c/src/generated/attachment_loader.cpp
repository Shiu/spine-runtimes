#include "attachment_loader.h"
#include <spine/spine.h>

using namespace spine;

void spine_attachment_loader_dispose(spine_attachment_loader self) {
    delete (AttachmentLoader*)self;
}

spine_region_attachment spine_attachment_loader_new_region_attachment(spine_attachment_loader self, spine_skin skin, const char * name, const char * path, spine_sequence sequence) {
    return (spine_region_attachment)((AttachmentLoader*)self)->newRegionAttachment(*((Skin*)skin), String(name), String(path), (Sequence *)sequence);
}

spine_mesh_attachment spine_attachment_loader_new_mesh_attachment(spine_attachment_loader self, spine_skin skin, const char * name, const char * path, spine_sequence sequence) {
    return (spine_mesh_attachment)((AttachmentLoader*)self)->newMeshAttachment(*((Skin*)skin), String(name), String(path), (Sequence *)sequence);
}

spine_bounding_box_attachment spine_attachment_loader_new_bounding_box_attachment(spine_attachment_loader self, spine_skin skin, const char * name) {
    return (spine_bounding_box_attachment)((AttachmentLoader*)self)->newBoundingBoxAttachment(*((Skin*)skin), String(name));
}

spine_path_attachment spine_attachment_loader_new_path_attachment(spine_attachment_loader self, spine_skin skin, const char * name) {
    return (spine_path_attachment)((AttachmentLoader*)self)->newPathAttachment(*((Skin*)skin), String(name));
}

spine_point_attachment spine_attachment_loader_new_point_attachment(spine_attachment_loader self, spine_skin skin, const char * name) {
    return (spine_point_attachment)((AttachmentLoader*)self)->newPointAttachment(*((Skin*)skin), String(name));
}

spine_clipping_attachment spine_attachment_loader_new_clipping_attachment(spine_attachment_loader self, spine_skin skin, const char * name) {
    return (spine_clipping_attachment)((AttachmentLoader*)self)->newClippingAttachment(*((Skin*)skin), String(name));
}
