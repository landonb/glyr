/***********************************************************
* This file is part of glyr
* + a commnadline tool and library to download various sort of musicrelated metadata.
* + Copyright (C) [2011]  [Christopher Pahl]
* + Hosted at: https://github.com/sahib/glyr
*
* glyr is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* glyr is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with glyr. If not, see <http://www.gnu.org/licenses/>.
**************************************************************/
#include "../../core.h"
#include "../../stringlib.h"
#include "../../utils.h"

#define SIZE_FO "<size name=\""
//#define SIZE_FO "<size name=\"extralarge\""
#define API_KEY API_KEY_LASTFM

#define URL_BEGIN "\">"
#define URL_ENDIN "</size>"

/* -------------------------------------------- */

const gchar * photos_lastfm_url(GlyrQuery * settings)
{
    return "http://ws.audioscrobbler.com/2.0/?method=artist.getimages&artist=%artist%&api_key="API_KEY;
}

/* -------------------------------------------- */

#define MAX_NUM_SIZE 16
static gint get_value(gchar * ref, gchar * name)
{
    gchar * field = strstr(ref,name);
    if(field != NULL)
    {
        field += strlen(name);
        gchar num[MAX_NUM_SIZE] = {};
        gint offset = 0;

        while(field[0] && field[0] != '"' && offset < MAX_NUM_SIZE)
        {
            num[offset++] = field[0];
            field++;
        }
        return strtol(num,NULL,10);
    }
    return 0;
}

/* -------------------------------------------- */

static gboolean size_fits(GlyrQuery * s, gchar ** ref)
{
    gboolean result = FALSE;
    if(ref != NULL)
    {
        gchar * search_ptr = ref[0];
        if(search_ptr != NULL)
        {
            search_ptr = strchr(search_ptr,'"');

            gint width  = get_value(search_ptr,"width=\"");
            gint height = get_value(search_ptr,"height=\"");
            gint ratio  = (width+height)/2;

            gboolean original_size_allowed = TRUE;
            if(g_strstr_len(ref[0],100,"original") != NULL)
            {
                /* Deny extremelly large images by default, except explicitely wanted */
                if(!(ratio >= 1000 && s->img_min_size >= 1000 && s->img_max_size == -1))
                {
                    original_size_allowed = FALSE;
                }
            }

            if(size_is_okay(ratio, s->img_min_size, s->img_max_size) == TRUE && original_size_allowed == TRUE)
            {
                result = TRUE;
            }

            search_ptr = strchr(search_ptr,'>');
        }
        ref[0] = search_ptr + 1;
    }
    return result;
}

/* -------------------------------------------- */

GList * photos_lastfm_parse(cb_object * capo)
{
    gchar * root = capo->cache->data;
    GList * r_list = NULL;
    gsize urlc = 0;

    while ( (root = strstr(root,SIZE_FO)) != NULL && continue_search(urlc,capo->s))
    {
        gchar * begin = root + strlen(SIZE_FO);
        if(size_fits(capo->s,&begin) == TRUE)
        {
            gchar * endin = strstr(begin,URL_ENDIN);
            if(endin != NULL)
            {
                gchar * urlb = copy_value(begin,endin);
                if(urlb != NULL)
                {
                    GlyrMemCache * cache = DL_init();
                    cache->data = urlb;
                    cache->size = strlen(urlb);
                    r_list = g_list_prepend(r_list,cache);
                    urlc++;
                }
            }
        }
        root += strlen(SIZE_FO) - 1;
    }
    return r_list;
}

/*--------------------------------------------------------*/

MetaDataSource photos_lastfm_src =
{
    .name = "lastfm",
    .key  = 'l',
    .parser    = photos_lastfm_parse,
    .get_url   = photos_lastfm_url,
    .type      = GET_ARTIST_PHOTOS,
    .quality   = 90,
    .speed     = 80,
    .endmarker = NULL,
    .free_url  = false
};
