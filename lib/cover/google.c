#define _GNU_SOURCE

#include <stdlib.h>
#include <string.h>

#include "google.h"

#include "../core.h"
#include "../stringop.h"

#define FIRST_RESULT "<td align=left valign=bottom width=23% style=\"padding-top:1px\"><a href=/imgres?imgurl="
#define END_OF_URL   "&imgrefurl="

const char * cover_google_url(glyr_settings_t * sets)
{
    const char * lang = NULL;
    switch(sets->lang)
    {
    case  GLYRL_US:
        lang = "com"  ;
        break;
    case  GLYRL_CA:
        lang = "ca"   ;
        break;
    case  GLYRL_UK:
        lang = "co.uk";
        break;
    case  GLYRL_FR:
        lang = "fr"   ;
        break;
    case  GLYRL_DE:
        lang = "de"   ;
        break;
    case  GLYRL_JP:
        lang = "co.jp";
        break;
    default:
        lang = "com";
    }

    const char * back = NULL;

    // Only use the 'large' option if really set high (>1000), large is usually verrrry incorrrect.
    if(sets->cover.min_size == -1)
    {
        back = "islt;qsvga";
    }
    else if(sets->cover.min_size <  50 && sets->cover.max_size <= 150)
    {
        back = "isz:i";
    }
    else if(sets->cover.min_size < 150 && sets->cover.max_size <= 300)
    {
        back = "isz:s";
    }
    else if(sets->cover.min_size < 300 && sets->cover.max_size <= 1000)
    {
        back = "islt:qsvga";
    }
    else
    {
        back = "islt:vga";
    }

    return strdup_printf("http://www.google.%s/images?q=%s+%s+album&safe=off&tbs=isch:1,iar:s,%s",lang,sets->artist,sets->album,back);
}

cache_list * cover_google_parse(cb_object * capo)
{
    // we blindly take the first result
    // actually we have not much of a choice (no, not Nr.42)
    cache_list * r_list = NULL;

    size_t urlc = 0;
    char * find = capo->cache->data;
    while( (find =  strstr(find+1,FIRST_RESULT)) != NULL && urlc < capo->s->number && urlc < capo->s->plugmax)
    {
        char * end_of_url;
        find += strlen(FIRST_RESULT);
        if((end_of_url = strstr(find, END_OF_URL)) != NULL)
        {
            char * url = copy_value(find,end_of_url);
            if(url)
            {
                if(!r_list) r_list = DL_new_lst();

                memCache_t * result = DL_init();
                result->data = url;
                result->size = strlen(url);

                DL_add_to_list(r_list,result);

                urlc++;
            }
        }
    }
    return r_list;
}