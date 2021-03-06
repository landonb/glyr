/***********************************************************
 * This file is part of glyr
 * + a commnadline tool and library to download various sort of music related metadata.
 * + Copyright (C) [2011]  [Christopher Pahl]
 * + Hosted at: https://github.com/sahib/glyr
 *
 * glyr is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * glyr is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with glyr. If not, see <http://www.gnu.org/licenses/>.
 **************************************************************/

#include "../../stringlib.h"
#include "../../core.h"
#include "../common/mbid_lookup.h"

#define API_ROOT "http://www.bbc.co.uk/music/artists/%s.xml"

/////////////////////////////////

#define CONTENT_BEGIN "<content>"
#define CONTENT_ENDIN "</content>"

static GlyrMemCache * parse_bbc_xml (GlyrMemCache * input)
{
    GlyrMemCache * result = NULL;
    char * content = get_search_value (input->data, CONTENT_BEGIN, CONTENT_ENDIN);
    if (content != NULL)
    {
        result = DL_init();
        result->data = content;
        result->dsrc = g_strdup (input->dsrc);
        result->size = strlen (content);
    }
    return result;
}

/////////////////////////////////

static const char * ainfo_bbcmusic_url (GlyrQuery * qry)
{
    return "http://musicbrainz.org/ws/2/artist?query=artist:${artist}";
}

/////////////////////////////////

static GList * ainfo_bbcmusic_parse (cb_object * capo)
{
    GList * result_list = NULL;

    char * mbid = mbid_parse_data (capo->cache, "artist", "name", capo->s->artist, capo->s);

    if (mbid != NULL)
    {
        char * full_url = g_strdup_printf (API_ROOT, mbid);
        if (full_url != NULL)
        {
            GlyrMemCache * bbc_xml = download_single (full_url, capo->s, NULL);
            if (bbc_xml != NULL)
            {
                GlyrMemCache * item = parse_bbc_xml (bbc_xml);
                if (item != NULL)
                {
                    result_list = g_list_prepend (result_list, item);
                }
                DL_free(bbc_xml);
            }
            g_free(full_url);
        }
        g_free(mbid);
    }

    return result_list;
}

/////////////////////////////////

MetaDataSource ainfo_bbcmusic_src =
{
    .name      = "bbcmusic",
    .key       = 'b',
    .free_url  = false,
    .type      = GLYR_GET_ARTIST_BIO,
    .parser    = ainfo_bbcmusic_parse,
    .get_url   = ainfo_bbcmusic_url,
    .quality   = 95,
    .speed     = 85,
    .endmarker = NULL,
    .lang_aware = false
};
