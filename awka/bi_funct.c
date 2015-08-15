/*------------------------------------------------------------*
 | bi_funct.c                                                 |
 | copyright 1999,  Andrew Sumner                             |
 | copyright 1991,  Michael D. Brennan                        |
 |                                                            |
 | This is a source file for the awka package, a translator   |
 | of the AWK programming language to ANSI C.                 |
 |                                                            |
 | The file is a heavily modified version of bi_funct.c from  |
 | Mawk, an implementation of the AWK processing language,    |
 | distributed by Michael Brennan under the GPL.              |
 |                                                            |
 | This program is free software; you can redistribute it     |
 | and/or modify it under the terms of the GNU General Public |
 | License as published by the Free Software Foundation;      |
 | either version 2 of the License, or any later version.     |
 |                                                            |
 | This program is distributed in the hope that it will be    |
 | useful, but WITHOUT ANY WARRANTY; without even the implied |
 | warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR    |
 | PURPOSE.  See the GNU General Public License for more      |
 | details.                                                   |
 |                                                            |
 | You should have received a copy of the GNU General Public  |
 | License along with this program; if not, write to the      |
 | Free Software Foundation, Inc., 675 Mass Ave, Cambridge,   |
 | MA 02139, USA.                                             |
 *------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Revision 1.1  1999/03/17
 * Basically reduced functions to stubs where possible, as
 * they don't need to do anything, just exist for the purposes
 * of parsing and translation.  - andrew.
 */

#include "awka.h"
#include "bi_funct.h"
#include "bi_vars.h"
#include "memory.h"
#include "init.h"
#include "files.h"
#include "fin.h"
#include "field.h"
#include "repl.h"
#include <math.h>

/* global for the disassembler */
char *bi_names[] =
{
   "length",
   "index",
   "substr",
   "sprintf",
   "sin",
   "cos",
   "atan2",
   "exp",
   "log",
   "int",
   "sqrt",
   "rand",
   "srand",
   "close",
   "system",
   "toupper",
   "tolower",
   "fflush",
   "gensub",
   NULL
};

BI_REC bi_funct[] =
{                                /* info to load builtins */

   "length", bi_length, 0, 1,        /* special must come first */
   "index", bi_index, 2, 2,
   "substr", bi_substr, 2, 3,
   "sprintf", bi_sprintf, 1, 255,
   "sin", bi_sin, 1, 1,
   "cos", bi_cos, 1, 1,
   "atan2", bi_atan2, 2, 2,
   "exp", bi_exp, 1, 1,
   "log", bi_log, 1, 1,
   "int", bi_int, 1, 1,
   "sqrt", bi_sqrt, 1, 1,
   "rand", bi_rand, 0, 0,
   "srand", bi_srand, 0, 1,
   "close", bi_close, 1, 1,
   "system", bi_system, 1, 1,
   "toupper", bi_toupper, 1, 1,
   "tolower", bi_tolower, 1, 1,
   "fflush", bi_fflush, 0, 1,
   "gensub", bi_gensub, 3, 4,

   (char *) 0, (PF_CP) 0, 0, 0} ;

char
bi_funct_find(char *name)
{
  int i=0;

  while (bi_names[i])
  {
    if (!strcmp(name, bi_names[i]))
      break;
    i++;
  }

  if (bi_names[i])
    return 1;
  return 0;
}

/* load built-in functions in symbol table */
void
bi_funct_init()
{
   register BI_REC *p ;
   register SYMTAB *stp ;

   /* length is special (posix bozo) */
   stp = insert(bi_funct->name) ;
   stp->type = ST_LENGTH ;
   stp->stval.bip = bi_funct ;

   for (p = bi_funct + 1; p->name; p++)
   {
      stp = insert(p->name) ;
      stp->type = ST_BUILTIN ;
      stp->stval.bip = p ;
   }

   /* seed rand() off the clock */
   {
      CELL c ;

      c.type = 0 ;  bi_srand(&c) ;
   }

}

char *
str_str(target, key, key_len)
   register char *target ;
   char *key ;
   unsigned key_len ;
{
   register int k = key[0] ;

   switch (key_len)
   {
      case 0:
         return (char *) 0 ;
      case 1:
         return strchr(target, k) ;
      case 2:
         {
            int k1 = key[1] ;
            while (target = strchr(target, k))
               if (target[1] == k1)  return target ;               else  target++ ;
            /*failed*/
            return (char *) 0 ;
         }
   }

   key_len-- ;
   while (target = strchr(target, k))
   {
      if (strncmp(target + 1, key + 1, key_len) == 0)  return target ;
      else  target++ ;
   }
   /*failed*/
   return (char *) 0 ;
}


/*
 * following functions are stubs, because the translator needs
 * them to exist but they are never actually called.
 */
CELL *
bi_gensub(sp)
   CELL *sp ;
{
   return (CELL *) NULL ;
}

CELL *
bi_argval(sp)
   CELL *sp ;
{
   return (CELL *) NULL ;
}

CELL *
bi_argcount(sp)
   CELL *sp ;
{
   return (CELL *) NULL ;
}

CELL *
bi_asort(sp)
   CELL *sp ;
{
   return (CELL *) NULL ;
}

CELL *
bi_alength(sp)
   CELL *sp ;
{
   return (CELL *) NULL ;
}

CELL *
bi_totitle(sp)
   CELL *sp ;
{
   return sp ;
}

CELL *
bi_ascii(sp)
   register CELL *sp ;
{
   return sp ;
}

CELL *
bi_char(sp)
  register CELL *sp ;
{
  return sp;
}


CELL *
bi_trim(sp)
   register CELL *sp ;
{
   return sp ;
}

CELL *
bi_rtrim(sp)
   register CELL *sp ;
{
   return sp ;
}


CELL *
bi_ltrim(sp)
   register CELL *sp ;
{
   return sp ;
}

CELL *
bi_left(sp)
   CELL *sp ;
{
   return sp ;
}

CELL *
bi_right(sp)
   CELL *sp ;
{
   return sp ;
}

CELL *
bi_min(sp)
  register CELL *sp ;
{
  return sp ;
}

CELL *
bi_max(sp)
  register CELL *sp ;
{
  return sp ;
}

/************************************************
  bit operations (extensions still)
 ************************************************/

CELL *
bi_and(sp)
  register CELL *sp ;
{
  return sp ;
}

CELL *
bi_or(sp)
  register CELL *sp ;
{
  return sp ;
}

CELL *
bi_xor(sp)
  register CELL *sp ;
{ 
  return sp ;
}

CELL *
bi_compl(sp)
  register CELL *sp ;
{
  return sp ;
}

CELL *
bi_lshift(sp)
  register CELL *sp ;
{
  return sp ;
}

CELL *
bi_rshift(sp)
  register CELL *sp ;
{
  return sp ;
}

CELL *
bi_time(sp)
   register CELL *sp ;
{
   return sp ;
}

CELL *
bi_systime(sp)
   register CELL *sp ;
{
   return sp ;
}

CELL *
bi_localtime(sp)
   register CELL *sp ;
{
   return sp ;
}

CELL *
bi_mktime(sp)
   register CELL *sp ;
{
   return sp ;
}

CELL *
bi_gmtime(sp)
   register CELL *sp ;
{
   return sp ;
}

CELL *
bi_strftime(sp)
   register CELL *sp ;
{
   return sp ;
}

/**************************************************
 string builtins (except split (in split.c) and [g]sub (at end))
 **************************************************/

CELL *
bi_length(sp)
   register CELL *sp ;
{
   return sp ;
}

CELL *
bi_index(sp)
   register CELL *sp ;
{
   return sp ;
}

/*  substr(s, i, n)
    if l = length(s)  then get the characters
    from  max(1,i) to min(l,n-i-1) inclusive */

CELL *
bi_substr(sp)
   CELL *sp ;
{
   return sp ;
}

/*
  match(s,r)
  sp[0] holds r, sp[-1] holds s
*/

CELL *
bi_match(sp)
   register CELL *sp ;
{
   return sp ;
}

CELL *
bi_toupper(sp)
   CELL *sp ;
{
   return sp ;
}

CELL *
bi_tolower(sp)
   CELL *sp ;
{
   return sp ;
}

CELL *
bi_sin(sp)
   register CELL *sp ;
{
   return sp ;
}

CELL *
bi_cos(sp)
   register CELL *sp ;
{
   return sp ;
}

CELL *
bi_atan2(sp)
   register CELL *sp ;
{
   return sp ;
}

CELL *
bi_log(sp)
   register CELL *sp ;
{
   return sp ;
}

CELL *
bi_exp(sp)
   register CELL *sp ;
{
   return sp ;
}

CELL *
bi_int(sp)
   register CELL *sp ;
{
   return sp ;
}

CELL *
bi_sqrt(sp)
   register CELL *sp ;
{
   return sp ;
}

CELL *
bi_srand(sp)
   register CELL *sp ;
{
   return sp ;
}

CELL *
bi_rand(sp)
   register CELL *sp ;
{
   return sp ;
}

CELL *
bi_close(sp)
   register CELL *sp ;
{
   return sp ;
}


CELL *
bi_fflush(sp)
   register CELL *sp ;
{
   return sp ;
}


CELL *
bi_system(sp)
   CELL *sp ;
{
   return sp ;
}

CELL *
bi_getline(sp)
   register CELL *sp ;
{
   return sp ;
}

CELL *
bi_sub(sp)
   register CELL *sp ;
{
   return sp ;
}

CELL *
bi_gsub(sp)
   register CELL *sp ;
{
   return sp ;
}

CELL *
bi_split(sp)
   register CELL *sp ;
{
   return sp ;
}

