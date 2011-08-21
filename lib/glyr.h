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
#ifndef GLYR_H
#define GLYR_H

/**
* @file glyr.h
* @brief All method declaration here. You should only need to include this file.
*
* All stable API of libglyr is right here.
*
* @author Christopher Pahl
* @version 0.6
* @date 2011-06-14
*/

/* All structs used by glyr are here */
#include "types.h"

/* */
#ifdef __cplusplus
extern "C"
{
#endif
    /**
    * @brief call this at startup
    * This is not threadsafe and glyr_cleanup should be called once for everytime you call glyr_init\n
    * Actually this method is only there to initialize libcurl, glyr only depends on the settings struct.\n
    */
    void glyr_init(void);

    /**
    * @brief Call this at program termination.
    * It's adviseable to call 'atexit(glyr_cleanup)' after glyr_init()\n
    * Not threadsafe!\n
    */
    void glyr_cleanup(void);

    /**
    * @brief The 'main' method of glyr. It starts the searching according to the settings in the settings param
    *
    * @param settings The setting struct controlling glyr. (See the glyr_opt_* methods)
    * @param error An optional pointer to an int, which gets filled with an error message, or GLYRE_OK on success
    * @param length An optional pointer storing the length of the returned list
    *
    * It takes a pointer to a GlyrQuery struct filled to your needs via the glyr_opt_* methods,\n
    * Once an item is found the callback (set via glyr_opt_dlcallback) is called with the item as parameter.\n
    * After return all items are listed in a GlyCacheList ready to be accessed, remember to delete it with glyr_free_list when done.\n
    *
    * @return A GlyCacheList containing all found data. See the struct reference for further details.
    */
    GlyrMemCache * glyr_get(GlyrQuery * settings, enum GLYR_ERROR * error, int * length);

    /**
    * @brief Init's the GlyrQuery structure to sane defaults.
    * Call this after creating the variable.
    *
    * @param glyrs The fresh GlyrQuery to be init'd.
    */
    void glyr_init_query(GlyrQuery * glyrs);

    /**
    * @brief Free all memory associated with this query, and restore default settings.
    * Do this always when you're done with this one.
    * @param sets The GlyrQuery to be destroyed
    */
    void glyr_destroy_query(GlyrQuery * sets);

    /**
    * @brief Free the memory in the GlyCacheList returned by glyr_get
    *
    * @param head The GlyCacheList to be free'd
    */
    void glyr_free_list(GlyrMemCache * head);

    /**
    * @brief Returns a newly allocated and initialized GlyrMemCache, mostly for use with glyr_gtrans_*
    * Don't forget to free it with glyr_free_cache
    * @return A newly allocated GlyrMemCache
    */
    GlyrMemCache * glyr_new_cache(void);

    /**
    * @brief Produces an exact copy of the GlyrMemCache source.
    *
    * @param source The GlyrMemCache to copy
    *
    * @return A newly allocated GlyrMemCache
    */
    GlyrMemCache * glyr_copy_cache(GlyrMemCache * source);

    /**
    * @brief Free the GlyrMemCache pointed to by c. You should set it to NULL also, as using it after this will crash your program.
    *
    * @param c An allocated GlyrMemCache
    */
    void glyr_free_cache(GlyrMemCache * c);

    /********************************************************
     * GlyOpt methods ahead - use them to control glyr_get() *
     ********************************************************/

    /**
    * @brief Set the callback that is executed once an item is ready downloaded
    *
    * @param settings The GlyrQuery settings struct to store this option in
    * @param dl_cb The callback to register, must have a prototype like this:\n
      	       enum GLYR_ERROR my_callback(GlyrMemCache * dl, struct GlyrQuery * s);
    * @param userp A pointer to a custom variable you can access inside the callback via s->callback.user_pointer;
    *
    * Note that you can return a certain integer in the callback:\n
    * GLYRE_IGNORE: To not add this item to the results.
    * GLYRE_OK: To add this item to the results and continue happily.
    * GLYRE_STOP_BY_CB: To stop right now and return the results. The last element will NOT be added.
    *
    * @return an errorID
    */
    enum GLYR_ERROR glyr_opt_dlcallback(GlyrQuery * settings, DL_callback dl_cb, void * userp);
    /**
    * @brief What type of metadata to search for. Must be one of GLYR_GET_TYPE enum.
    *
    * @param s The GlyrQuery settings struct to store this option in
    * @param type A member of the GLYR_GET_TYPE enum, set this before you set anything else.
    *
    * @return an errorID
    */
    enum GLYR_ERROR glyr_opt_type(GlyrQuery * s, enum GLYR_GET_TYPE type);
    /**
    * @brief The artist field. libglyr will try to format it to fit the best.
    *
    * @param s The GlyrQuery settings struct to store this option in
    * @param artist A nullterminated char, a copy of the string will be held internally so you can savely modify your version.
    *
    * This field is required for all getters. You are required to fill it.
    *
    * @return an errorID
    */
    enum GLYR_ERROR glyr_opt_artist(GlyrQuery * s, char * artist);
    /**
    * @brief The album field. libglyr will try to format it to fit the best.
    *
    * @param s The GlyrQuery settings struct to store this option in.
    * @param album A nullterminated char, a copy of the string will be held internally so you can savely modify your version.
    *
    *	Required for the following getters:
    *	  - albumlist
    *	  - cover
    *	  - albumreview
    *     - similarsongs
    *	  - tracklist
    *
    *	Optional for those:
    *	  - tags
    *	  - relations
    *
    *
    * @return an errorID
    */
    enum GLYR_ERROR glyr_opt_album(GlyrQuery * s,  char * album);
    /**
    * @brief The title field. libglyr will try to format it to fit the best.
    *
    * @param s The GlyrQuery settings struct to store this option in.
    * @param title A nullterminated char, a copy of the string will be held internally so you can savely modify your version.
    *
    *	Required for:
    *	  - lyrics
    *	Optional for:
    *	  - tags
    *	  - relations
    *
    * @return an errorID
    */
    enum GLYR_ERROR glyr_opt_title(GlyrQuery * s,  char * title);
    /**
    * @brief Maximum size a cover may have (assuming the cover is quadratic, only one size is required)
    *
    * @param s The GlyrQuery settings struct to store this option in.
    * @param size The max. size in pixel
    *
    * Please note: libglyr takes this as a hint, and not as an absolute measure. You may find yourself with slightly oversized or undersized covers,\n
    * but generally overall in the range between min and max. \n
    *
    * @return an errorID
    */
    enum GLYR_ERROR glyr_opt_img_minsize(GlyrQuery * s, int size);
    /**
    * @brief Minimum size a image-item may have (assuming the image is quadratic, only one size is required)
    *
    * @param s The GlyrQuery settings struct to store this option in.
    * @param size The min. size in pixel
    *
    * Note: Also see glyr_opt_img_maxsize()
    *
    * @return an errorID
    */
    enum GLYR_ERROR glyr_opt_img_maxsize(GlyrQuery * s, int size);
    /**
    * @brief The number of jobs that may be started in parallel
    *
    * @param s The GlyrQuery settings struct to store this option in.
    * @param val the number as unsigned long
    *
    * This does not acutally limit the number of parallel downloads,\n
    * rather it limits the number of providers that are tried in parallel\n
    * Set this to a value of 0 to let libglyr guess the best value.\n
    *
    *
    * @return an errorID
    */
    enum GLYR_ERROR glyr_opt_parallel(GlyrQuery * s, unsigned long val);
    /**
    * @brief Amout of seconds to wait before cancelling an download
    *
    * @param s The GlyrQuery settings struct to store this option in.
    * @param val Timeout in seconds.
    *
    * If more than one item is downloaded in parallel, the timeout will be changed accordingly.\n
    * Default is 20 seconds.
    *
    * @return an errorID
    */
    enum GLYR_ERROR glyr_opt_timeout(GlyrQuery * s, unsigned long val);
    /**
    * @brief Max number of redirects to
    *
    * @param s The GlyrQuery settings struct to store this option in.
    * @param val an unsigned integer
    *
    * A value of 0 is allowed, but may break certain plugins.\n
    * Default = 1\n
    *
    * @return an errorID
    */
    enum GLYR_ERROR glyr_opt_redirects(GlyrQuery * s, unsigned long val);

    /**
    * @brief  Set the useragent during making progresses
    *
    * @param s The GlyrQuery settings struct to store this option in.
    * @param useragent a null terminated string containging everything you want
    *
    * Some provider may require an useragent, setting it to an empty string "" \n
    * might not be safe therefore\n
    * Default useragents is "libglyr/<version name>" or similar
    *
    * @return an errorID
    */
    enum GLYR_ERROR glyr_opt_useragent(GlyrQuery * s, const char * useragent);
    /**
    * @brief Language for providers offering multilingual data.
    *
    * @param s The GlyrQuery settings struct to store this option in.
    * @param langcode
    *	The language used for providers with multilingual content.
    *	It is given in ISO-639-1 codes, i.e 'de','en','fr' etc.
    *
    *	List of providers recognizing this option:\n
    *	   * cover/amazon (which amazon server to query)
    *	   * cover/google (which google server to query)
    *	   * ainfo/lastfm (the language the biography shall be in)\n
    *
    *	(Use only these providers if you really want ONLY localized content)\n
    *	If no language specified the language defaults to english ("en")\n
    *   The special value 'auto' is recognized, in which case the language will be\n
    *   guessed from your current locale.
    *
    * @return an errorID
    */
    enum GLYR_ERROR glyr_opt_lang(GlyrQuery * s, char * langcode);
    /**
    * @brief Set the number of items to search.
    *
    * @param s The GlyrQuery settings struct to store this option in.
    * @param num the number as an integer
    *
    *	How many items to search for (1 to INT_MAX)\n
    *	This is not the number of items actually returned then,\n
    *	because libglyr is not able to find 300 songtexts of the same song,\n
    *	or libglyr filters duplicate items before returning.\n
    *       It will try to get as close to this number, but not higher.
    *       If '0' is specified, libglyr will try to find all the things.
    *
    * @return an errorID
    */
    enum GLYR_ERROR glyr_opt_number(GlyrQuery * s, unsigned int num);
    /**
    * @brief Set libglyr's verbosity level (debug)
    *
    * @param s The GlyrQuery settings struct to store this option in.
    * @param level The level as an integer, see description below
    *
    *        0) nothing but fatal errors.\n
    *        1) warnings and important notes.\n
    *        2) normal, additional information what libglyr does.\n
    *        3) basic debug output.\n
    *        4) libcurl debug output.\n
    *
    * @return an errorID
    */
    enum GLYR_ERROR glyr_opt_verbosity(GlyrQuery * s, unsigned int level);
    /**
    * @brief Define the providers you want to use
    *
    * @param s The GlyrQuery settings struct to store this option in.
    * @param from a string, see below
    *
    *        Use this to define what providers you want to use.\n
    *        Every provider has a name and a key which is merely a shortcut for the name.\n
    *        Specify all providers in a semicolon seperated list.\n
    *        Type 'glyrc -H' for a complete list of all providers for each getter.\n
    *
    *          Example:\n
    *            "amazon;google" \n
    *           "a;g" - same with keys\n
    *
    *        You can also prepend each word with a '+' or a '-' ('+' is assumend without),\n
    *        which will add or remove this provider from the list respectively.\n
    *        Additionally you may use the predefined groups 'safe','unsafe','fast','slow','special'.\n
    *
    *          Example:\n
    *           "+fast;-amazon" which will enable last.fm and lyricswiki.\n
    *
    *
    * @return an errorID
    */
    enum GLYR_ERROR glyr_opt_from(GlyrQuery * s, const char * from);

    /**
    * @brief Define the maximum number of items a provider may download
    *
    * @param s The GlyrQuery settings struct to store this option in.
    * @param plugmax
    *
    *	Use this to scatter the results over more providers, to get different results.\n
    *	You can set it also to -1 what allows an infinite number of items (=> default)
    *
    * @return an errorID
    */
    enum GLYR_ERROR glyr_opt_plugmax(GlyrQuery * s, int plugmax);

    /**
    * @brief Define allowed image formats
    *
    * @param s The GlyrQuery settings struct to store this option in.
    * @param formats A comma seperated list of format specifiers, e.g. "png;jpeg"
    *
    * Awaits a string with a semicolon seperated list of allowed formats.\n
    * The case of the format is ignored.\n
    *
    * Example:\n
    * "png;jpg" would allow png,jpeg,jpg,JPEG,jpg, but not gifs.\n
    * The names of the format are the MIME types found in HTTP headers.
    * A list of types is here: http://www.w3schools.com/media/media_mimeref.asp
    *
    * A value of NULL will default to "png;jpeg;tiff"
    *
    * @return an errorID
    */

    enum GLYR_ERROR glyr_opt_allowed_formats(GlyrQuery * s, const char * formats);
    /**
    * @brief Define if image items (i.e, covers, photos) are downloaded.
    *
    * @param s The GlyrQuery settings struct to store this option in.
    * @param download
    *
    *        For image getters only.\n
    *        If set to true images are also coviniently downloaded and returned.\n
    *        Otherwise, just the URL is returned for your own use.\n
    *
    *        Default to 'true', 'false' would be a bit more searchengine like.\n
    *
    * @return an errorID
    */
    enum GLYR_ERROR glyr_opt_download(GlyrQuery * s, bool download);

    /**
    * @brief Set the max. tolerance for fuzzy matching
    *
    * @param s The GlyrQuery settings struct to store this option in.
    * @param fuzz
    *
    *	Set the maximum amount of inserts, edits and substitutions, a search results\n
    *       may differ from the artist and/or album and/or title.\n
    *       The difference between two strings is measured as the 'Levenshtein distance',\n
    *       i.e, the total amount of inserts,edits and substitutes needed to convert string a to b.\n
    *
    *       Example:\n
    *          "Equilibrium" <=> "Aqilibriums" => Distance=3\n
    *          With a fuzzyness of 3 this would pass the check, with 2 it won't.\n
    *
    *       Higher values mean more search results, but more inaccuracy. \n
    *       Default is 4.
    *
    * @return an errorID
    */
    enum GLYR_ERROR glyr_opt_fuzzyness(GlyrQuery * s, int fuzz);

    /**
    * @brief Weight ratio between speed and quality
    *
    * @param s The GlyrQuery settings struct to store this option in.
    * @param ratio A float, where 0.0 if full speed, and 1.0 full quality
    *
    *   0.00 means highest speed, you're kinda lucky if you have the right result there.
    *   1.00 Takes possibly longer, but delivers usually good results.
    *   0.85 is the current default value.
    *
    *   All other values, smaller 0.0, greater 1.0 are clamped to 0.0 / 1.0
    *
    * @return
    */
    enum GLYR_ERROR glyr_opt_qsratio(GlyrQuery * s, float ratio);

    /**
    * @brief Set the proxy to use
    *
    * @param s The GlyrQuery settings struct to store this option in.
    * @param proxystring the proxy setting.
    *
    *  NULL for none, otherwise see the documentation of curl_easy_setopt(CURLOPT_PROXY) how to set this.
    *  Synatx: [protocol://][user:pass@]Domain[:port]
    *  Example: "http://Proxy.fh-hof.de:3128"
    *
    * If empty the global env $http_proxy shall be used, if present.
    *
    * @return an errorID
    */
    enum GLYR_ERROR glyr_opt_proxy(GlyrQuery * s, const char * proxystring);

    /**
    * @brief Forces UTF8 encoding for text items
    *
    * @param s A GlyrQuery with the timeout and redirect values filled to your needs.
    * @param force_utf8 true to foce, false to accept other encodings
    *
    * Often this will option won't have serious impact, except for a view providers that don't deliever exact UTF8,
    * due to corrupted data (twice encoded like metrolyrics), but may deliever subsets of UTF8.
    * Check is done via g_utf8_validate()
    *
    * @return A GlyrMemCache containing the data
    */
    enum GLYR_ERROR glyr_opt_force_utf8(GlyrQuery * s, bool force_utf8);

    /**
    * @brief A convinience method to download the content at the URl $url, according to the settings in $s
    * Actually only the redirect and timeout parameters are used here.
    *
    * @param url The url to download as nullterminated string. Must be a vaild URL.
    * @param s A GlyrQuery with the timeout and redirect values filled to your needs.
    *
    * @return A GlyrMemCache containing the data
    */
    GlyrMemCache * glyr_download(const char * url, GlyrQuery * s);

    /**
    * @brief Many methods use an returnvalue, or error parameters to inform you about errors
    * Use this method to get a descriptive message you can print.
    *
    * @param ID The returned error
    *
    * @return A descriptive nullterminated string, do not pass to free
    */
    const char * glyr_strerror(enum GLYR_ERROR ID);

    /**
    * @brief Returns versioning information, including compiletime
    *
    *  Example: \n
    *    Version 0.4 (Larcenous Locust (dev)) of [May 20 2011] compiled at [19:12:37]
    *
    * @return A nullterminated string, do not free
    */
    const char * glyr_version(void);

    /**
    * @brief Writes data to a specified path
    *
    * @param data The data to write.
    * @param path The path to write data at.
    *
    * Writes data to path $path, special values for $path can be 'stdout','stderr' or 'null',\n
    * which are pretty selfexplaining.
    *
    * @return An error id.
    */
    int glyr_write(GlyrMemCache * data, const char * path);


    /**
    * @brief Updates the md5sum field of the cache c
    *
    * @param c a valid memcahe
    */
    void glyr_update_md5sum(GlyrMemCache * c);


    /**
    * @brief Prints information about a GlyrMemCache to stderr
    *
    * @param cacheditem The GlyrMemCache to be printed
    */
    void glyr_printitem(GlyrMemCache * cacheditem);


    /**
    * @brief get information about existing Fetcher and Source
    *
    *
    * A Doubly linked list of Fetcher is returned, each having a field 'head',
    * being a pointer to a doubly linked list of GlyrSourceInfos
    *
    * @return A newly GlyrFetcherInfo structure, you can iterate over.
    */
    GlyrFetcherInfo * glyr_get_plugin_info(void);

    /**
    * @brief Free the data from glyr_get_plugin_info()
    *
    * This method also set the pointer to NULL, for safety reasons.
    *
    * @param info A reference to the return value fo glyr_get_plugin_info()
    */
    void glyr_free_plugin_info(GlyrFetcherInfo ** info);

    /**
    * @brief Converts a GLYR_DATA_TYPE type to a string
    *
    * @param type a member of the GLYR_DATA_TYPE enum, TYPE_COVER_PRI e.g.
    *
    * @return a statically allocated string, do not free
    */
    const char * glyr_type_to_string(enum GLYR_DATA_TYPE type);

#ifdef _cplusplus
}
#endif

#endif
