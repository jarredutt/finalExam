/*
	CS 3560 Spring 2018
	Final Exam Task B
	Jarred Utt
*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include "wc.h"
using namespace	std;

count_t total_ccount = 0;
count_t total_wcount = 0;
count_t total_lcount = 0;
count_t ccount;
count_t wcount;
count_t lcount;

unsigned long countLine(char* pName);
unsigned long countChar(char* pName);
void report (char *file, count_t ccount, count_t wcount, count_t lcount);
int getword (FILE *fp);
static void perrf (char *fmt, ...);
unsigned long counter (char *file);

int main (int argc, char **argv) //int argc, char **argv
{
    int i;
       
       if (argc < 2)
       {
     		countLine("Ohio University");
     		countChar("Athens");
       }
       
       for (i = 1; i < argc; i++)
         counter (argv[i]);
       
       if (argc > 2)
         report ("total", total_ccount, total_wcount, total_lcount);


       return 0;
}

unsigned long countLine(char* pName)
{
       FILE *fp = fopen (pName, "r");
       
       if (!fp)
         perrf ("cannot open file");
     
       ccount = wcount = lcount = 0;
       while (getword (fp))
         ;
       fclose (fp);
     
       report (pName, ccount, wcount, lcount);
       total_ccount += ccount;
       total_wcount += wcount;
       total_lcount += lcount;
       return lcount;
}

unsigned long countChar(char* pName)
{
	FILE *fp = fopen (pName, "r");
       
       if (!fp)
         perrf ("cannot open pName `%s'", pName);
     
       ccount = wcount = lcount = 0;
       while (getword (fp))
         ;
       fclose (fp);
     
       report (pName, ccount, wcount, lcount);
       total_ccount += ccount;
       total_wcount += wcount;
       total_lcount += lcount;
       return ccount;
}

void
     report (char *pName, count_t ccount, count_t wcount, count_t lcount)
     {
       printf ("%6lu %6lu %6lu %s\n", lcount, wcount, ccount, pName);
     }
     
     /* Return true if C is a valid word constituent */
     static int
     isword (unsigned char c)
     {
       return isalpha (c);
     }
     
     /* Increase character and, if necessary, line counters */
     #define COUNT(c)       \
           ccount++;        \
           if ((c) == '\n') \
             lcount++;
     
     /* Get next word from the input stream. Return 0 on end
        of file or error condition. Return 1 otherwise. */
     int
     getword (FILE *fp)
     {
       int c;
       int word = 0;
       
       if (feof (fp))
         return 0;
           
       while ((c = getc (fp)) != EOF)
         {
           if (isword (c))
             {
               wcount++;
               break;
             }
           COUNT (c);
         }
     
       for (; c != EOF; c = getc (fp))
         {
           COUNT (c);
           if (!isword (c))
             break;
         }
     
       return c != EOF;
     }

     static void perrf (char *fmt, ...)
     {
       va_list ap;
       
       va_start (ap, fmt);
       error_print (1, fmt, ap);
       va_end (ap);
     }

     static void error_print (int perr, char *fmt, va_list ap)
     {
       vfprintf (stderr, fmt, ap);
       if (perr)
         perror (" ");
       else
         fprintf (stderr, "\n");
       exit (1);  
     }

     unsigned long counter (char *file)
     {
       FILE *fp = fopen (file, "r");
       
       if (!fp)
         perrf ("cannot open file `%s'", file);
     
       ccount = wcount = lcount = 0;
       while (getword (fp))
         ;
       fclose (fp);
     
       report (file, ccount, wcount, lcount);
       total_ccount += ccount;
       total_wcount += wcount;
       total_lcount += lcount;
       return ccount;
     }