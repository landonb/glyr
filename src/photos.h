
#ifndef PHOTOS_H
#define PHOTOS_H

#include "types.h"

plugin_t * glyr_get_photo_providers(void);
char * get_photos(glyr_settings_t * settings);

#endif