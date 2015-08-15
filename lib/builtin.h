/*--------------------------------------------------*
 | builtin.h                                        |
 | Header file for builtin.c, part of the Awka      |
 | Library, Copyright 1999, Andrew Sumner.          |
 | This file is covered by the GNU General Public   |
 | License (GPL).                                   |
 *--------------------------------------------------*/

#ifndef _BUILTIN_H
#define _BUILTIN_H

#define a_KEEP 0
#define a_TEMP 1

#define a_BI_TOUPPER 1
#define a_BI_TOLOWER 2
#define a_BI_TOTITLE 3

#ifndef _IN_LIBRARY
static double
awka_length(a_VAR *v)
{
  awka_gets1(v);
  return (double) v->slen;
}

static double
awka_index(a_VAR *va, a_VAR *vb)
{
  register char *c, *a, *b;

  a = awka_gets1(va);
  b = awka_gets1(vb);
  c = strstr(a, b);

  if (c)
    return (double) ((c - a) + 1);
  return 0;
}

static double
awka_and(a_VAR *va, a_VAR *vb)
{
  return (double) ((int) awka_getd1(va) & (int) awka_getd1(vb));
}

static double
awka_or(a_VAR *va, a_VAR *vb)
{
  return (double) ((int) awka_getd1(va) | (int) awka_getd1(vb));
}

static double
awka_xor(a_VAR *va, a_VAR *vb)
{
  return (double) ((int) awka_getd1(va) ^ (int) awka_getd1(vb));
}

static double
awka_compl(a_VAR *va)
{
  return (double) (~((int) awka_getd1(va)));
}

static double
awka_lshift(a_VAR *va, a_VAR *vb)
{
  return (double) ((int) awka_getd1(va) << (int) awka_getd1(vb));
}

static double
awka_rshift(a_VAR *va, a_VAR *vb)
{
  return (double) ((int) awka_getd1(va) >> (int) awka_getd1(vb));
}

#endif

a_VAR *    awka_getstringvar(char);
a_VAR *    awka_getdoublevar(char);
a_VAR *    awka_strconcat2(char, a_VAR *, a_VAR *);
a_VAR *    awka_strconcat3(char, a_VAR *, a_VAR *, a_VAR *);
a_VAR *    awka_strconcat4(char, a_VAR *, a_VAR *, a_VAR *, a_VAR *);
a_VAR *    awka_strconcat5(char, a_VAR *, a_VAR *, a_VAR *, a_VAR *, a_VAR *);
a_VAR *    awka_strconcat(char, a_VARARG *);
a_VAR *    awka_match(char, char, a_VAR *, a_VAR *, a_VAR *);
a_VAR *    awka_substr(char, a_VAR *, double, double);
a_VAR *    awka_sub(char, char, int, a_VAR *, a_VAR *, a_VAR *);
a_VAR *    awka_gensub(char, a_VAR *, a_VAR *, a_VAR *, a_VAR *);
a_VAR *    awka_tocase(char, char, a_VAR *);
a_VAR *    awka_system(char, a_VAR *);
a_VAR *    awka_trim(char, a_VARARG *);
a_VAR *    awka_ltrim(char, a_VARARG *);
a_VAR *    awka_rtrim(char, a_VARARG *);
double     awka_rand();
a_VAR *    awka_srand(char, a_VARARG *);
a_VAR *    awka_left(char, a_VAR *, a_VAR *);
a_VAR *    awka_right(char, a_VAR *, a_VAR *);
a_VAR *    awka_ascii(char, a_VARARG *);
a_VAR *    awka_char(char, a_VAR *);
a_VAR *    awka_time(char, a_VARARG *);
a_VAR *    awka_systime(char);
a_VAR *    awka_gmtime(char, a_VARARG *);
a_VAR *    awka_localtime(char, a_VARARG *);
a_VAR *    awka_mktime(char, a_VARARG *);
a_VAR *    awka_strftime(char, a_VARARG *);
a_VAR *    awka_min(char, a_VARARG *);
a_VAR *    awka_max(char, a_VARARG *);
a_VAR *    awka_sprintf(char, a_VARARG *);
a_VAR *    awka_getline(char, a_VAR *, char *, int, char);
a_VAR *    awka_fflush(char, a_VARARG *);
a_VAR *    awka_close(char, a_VARARG *);
void       awka_printf( char *, int, int, a_VARARG * );
void       awka_print( char *, int, int, a_VARARG * );
a_VARARG * awka_vararg(char, a_VAR *var, ...);
a_VARARG * awka_arg0(char);
a_VARARG * awka_arg1(char, a_VAR *);
a_VARARG * awka_arg2(char, a_VAR *, a_VAR *);
a_VARARG * awka_arg3(char, a_VAR *, a_VAR *, a_VAR *);

#define awka_length0   awka_length(awka_doln(0,0))
                          
#ifndef BUILTIN_HOME
extern int _awka_file_read;
#endif

#endif
