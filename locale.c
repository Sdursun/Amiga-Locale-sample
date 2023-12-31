
/****************************************************************

   This file was created automatically by `FlexCat 2.18'
   from "hello.cd".

   Do NOT edit by hand!

****************************************************************/

/****************************************************************
    This file uses the auto initialization features of
    Dice, gcc and SAS/C, respectively.

    Dice does this by using the __autoinit and __autoexit
    keywords, whereas SAS/C uses names beginning with _STI
    or _STD, respectively. gcc uses the asm() instruction
    to emulate C++ constructors and destructors.

    Using this file you don't have *all* the benefits of
    locale.library (no Locale or Language arguments are
    supported when opening the catalog). However, these are
    *very* rarely used, so this should be sufficient for most
    applications.

    If you really need all the bells and whistles or you
    are using another compiler, you should use the source
    description C_c_V21.sd instead.
****************************************************************/

/*
    Include files and compiler specific stuff
*/

#include <libraries/locale.h>

#if defined(__SASC)  ||  defined(_DCC)
#include <proto/exec.h>
#include <proto/locale.h>
typedef struct Library LocaleBase_t;
#elif defined(__GNUC__)
#include <inline/exec.h>
#include <inline/locale.h>
typedef struct LocaleBase LocaleBase_t;
#else
#error "I don't know how to handle your compiler."
#endif

#if defined(__SASC)
#define __autoinit
#define __autoexit
#endif

#if defined(__GNUC__)
#define __autoinit __attribute__ ((constructor))
#define __autoexit __attribute__ ((destructor))
#endif


/*
    Variables
*/
struct FC_Type
{   LONG   ID;
    STRPTR Str;
};
const struct FC_Type _msgContinue = { 0, (STRPTR) "Continue" };

static struct Catalog *hello_Catalog = NULL;

LocaleBase_t *LocaleBase;





STATIC __autoinit VOID _STIOpenCatalog(VOID)

  {
    STATIC const struct TagItem tags[] =
      {
	{ OC_BuiltInLanguage, (ULONG) "english" },
	{ OC_Version, 2 },
	{ TAG_DONE, 0 }
      };
    if ((LocaleBase = (LocaleBase_t *)
		      OpenLibrary((STRPTR) "locale.library", 38)))
    {
      hello_Catalog = OpenCatalogA(NULL, (STRPTR) "hello.catalog",
				(struct TagItem *) tags);
    }
  }



STATIC __autoexit VOID _STDCloseCatalog(VOID)

  {
    if (LocaleBase)
      {
	CloseCatalog(hello_Catalog);
	hello_Catalog = NULL;
	CloseLibrary((struct Library *) LocaleBase);
      }
  }



STRPTR GetString(struct FC_Type *fcstr)

  {
    STRPTR defaultstr;
    LONG strnum;

    strnum = fcstr->ID;
    defaultstr = fcstr->Str;

    return(hello_Catalog ? GetCatalogStr(hello_Catalog, strnum, defaultstr) :
			defaultstr);
  }
