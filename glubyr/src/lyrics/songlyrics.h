#ifndef L_SONGLYRICS_H
#define L_SONGLYRICS_H

#include "../core.h"

const char * lyrics_songlyrics_url(glyr_settings_t * settings);
cache_list * lyrics_songlyrics_parse(cb_object * capo);

#endif