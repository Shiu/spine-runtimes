#ifndef SPINE_SPINE_ATLAS_ATTACHMENT_LOADER_H
#define SPINE_SPINE_ATLAS_ATTACHMENT_LOADER_H

#include "../base.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

SPINE_C_API spine_atlas_attachment_loader spine_atlas_attachment_loader_create(spine_atlas atlas);

SPINE_C_API void spine_atlas_attachment_loader_dispose(spine_atlas_attachment_loader self);

SPINE_C_API spine_region_attachment spine_atlas_attachment_loader_new_region_attachment(spine_atlas_attachment_loader self, spine_skin skin,
																						const char *name, const char *path, spine_sequence sequence);
SPINE_C_API spine_mesh_attachment spine_atlas_attachment_loader_new_mesh_attachment(spine_atlas_attachment_loader self, spine_skin skin,
																					const char *name, const char *path, spine_sequence sequence);
SPINE_C_API spine_bounding_box_attachment spine_atlas_attachment_loader_new_bounding_box_attachment(spine_atlas_attachment_loader self,
																									spine_skin skin, const char *name);
SPINE_C_API spine_path_attachment spine_atlas_attachment_loader_new_path_attachment(spine_atlas_attachment_loader self, spine_skin skin,
																					const char *name);
SPINE_C_API spine_point_attachment spine_atlas_attachment_loader_new_point_attachment(spine_atlas_attachment_loader self, spine_skin skin,
																					  const char *name);
SPINE_C_API spine_clipping_attachment spine_atlas_attachment_loader_new_clipping_attachment(spine_atlas_attachment_loader self, spine_skin skin,
																							const char *name);
SPINE_C_API spine_atlas_region spine_atlas_attachment_loader_find_region(spine_atlas_attachment_loader self, const char *name);

#ifdef __cplusplus
}
#endif

#endif /* SPINE_SPINE_ATLAS_ATTACHMENT_LOADER_H */
