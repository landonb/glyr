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

#include "../core.h"
#include "../stringlib.h"

/* ------------------------------------- */

static GList * async_dl_callback(cb_object * capo, void * userptr, bool * stop_download, gint * add_item)
{
	if(capo->cache != NULL)
	{
		/* Sanitize this */
		GHashTable * prov_url_table = (GHashTable*)userptr;
		capo->cache->is_image = true;
		capo->cache->type = TYPE_COVER;

		GlyMemCache * old_cache = g_hash_table_lookup(prov_url_table,capo->cache->dsrc);

		if(old_cache != NULL)
		{
			capo->cache->prov       = (old_cache->prov!=NULL) ? g_strdup(old_cache->prov) : NULL;
			capo->cache->img_format = (old_cache->img_format) ? g_strdup(old_cache->img_format) : NULL;
			capo->s->callback.download(capo->cache,capo->s);
			*add_item += 1;
		}
	}
	return NULL;
}

/* ------------------------------------- */

static GList * factory(GlyQuery * s, GList * list) {
	/* Just return URLs */
	if(s->download == false)
	{
		for(GList * elem = list; elem; elem = elem->next) {
			GlyMemCache * img = elem->data;
			img->is_image = true;
			img->type = TYPE_IMG_URL;
		}	
		return g_list_copy(list);

		/* Downloading is requested */
	} else {
		/* Convert to a list of URLs first */
		GList * url_list  = NULL; 

		/* Hashtable to associate the provider name with the corresponding URL */
		GHashTable * cache_url_table = g_hash_table_new_full(g_str_hash,g_str_equal,
				NULL,
				(GDestroyNotify)DL_free
				);

		/* Iterate over all caches and turn them to GList */
		for(GList * item = list; item; item = item->next) {
			GlyMemCache * cache = item->data;

			/* Make a copy, since we free the cache */
			gchar * url_double = g_strdup(cache->data);
			url_list  = g_list_prepend(url_list,url_double);

			/* Fill in the URL */
			g_hash_table_insert(cache_url_table,(gpointer)url_double,(gpointer)cache);
		}		

		/* Download images in parallel */
		GList * dl_raw_images = async_download(url_list,s,1,1 * (g_list_length(url_list)/4),async_dl_callback,cache_url_table);

		/* Freeing Party */
		g_hash_table_destroy(cache_url_table);
		g_list_free_full(url_list,g_free);

		/* Ready to save images */
		return dl_raw_images;
	}
	return NULL;
}

/* ------------------------------------- */

bool vdt_cover(GlyQuery * settings)
{
	if (settings && settings->artist && settings->album)
	{
		/* validate size */
		if(settings->cover.min_size <= 0)
			settings->cover.min_size = -1;

		if(settings->cover.max_size <= 0)
			settings->cover.max_size = -1;

		return true;
	}
	else
	{
		return false;
	}
}

/* ------------------------------------- */

/* PlugStruct */
MetaDataFetcher glyrFetcher_cover = {
	.name = "Cover Fetcher",
	.type = GET_COVERART,
	.validate = vdt_cover,
	.init    = NULL,
	.destroy = NULL,
	.finalize = factory
};

/* ------------------------------------- */
