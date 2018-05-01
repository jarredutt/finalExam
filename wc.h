#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#ifndef WC
typedef unsigned long count_t;
static void error_print (int perr, char *fmt, va_list ap);
static void errf (char *fmt, ...);
static void perrf (char *fmt, ...);
void report (char *file, count_t ccount, count_t wcount, count_t lcount);
int getword (FILE *fp);
unsigned long counter (char *file);
#endif