#ifndef P_FLICKR_H
#define P_FLICKR_H

#include "../core.h"

const char * photos_flickr_url(glyr_settings_t * settings);
cache_list * photos_flickr_parse(cb_object * capo);

#endif