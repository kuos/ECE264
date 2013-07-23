/*
 * Please fill the functions in this file.
 * You can add additional functions. 
 *
 * For this assignment, you must use qsort and give appropriate
 * comparison functions.
 *
 * You can assume that the input files have no empty lines and the
 * last line ends with '\n'.  You can count the number of lines by
 * counting the occurrences of '\n'.
 *
 * Hint: 
 * You can write additonal functions.
 *
 */

#include "pa02.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INT     0
#define STRING  1
#define FAILURE 0
#define SUCCESS 1

int countLine(char *inName);
int cmpInt( const void *a, const void *b);
int cmpStr(const void *s1, const void *s2);



/*
 * =================================================================
 * read the integers from the file whose name is inName
 * sort the integers
 * stored the sorted integers in the file whose name is outName
 */

void sortInt(char * inName, char * outName)
{
  int numLine = countLine(inName);              //The number of lines in the file
  int *arr = malloc(sizeof(int)*numLine);       //Allocate int array memory
   
  //Start Input File:
  FILE *f = fopen(inName, "r");
  int i = 0;

  while(i <= numLine)
    {
      fscanf(f, "%d",&arr[i]);
      i++;
    }

  fclose(f);

  qsort(arr, numLine, sizeof(int),cmpInt);

  //Start Output File:
  FILE *f2 = fopen(outName, "w");
  
  int j = 0;
  for (j=0; j < numLine; j++)
    {
      fprintf (f2, "%d\n",arr[j]);
    }

  free(arr);
  fclose(f2);
}

/*
 * =================================================================
 * read the strings from the file whose name is inName
 * sort the strings
 * stored the sorted strings in the file whose name is outName
 *
 * The strings are sorted by ASCII order (using strcmp). Thus, 'B' will
 * appear before 'a'.
 */

  /*
  char read;
  int line;
  int buffer[LINELENGTH] = {0};
  while((read = fgetc(f)) != EOF)
    {
      if(line  == '\n')
	{
	  line++;
	}
      else
	{
	  buffer[line]+=1;  
	}
    } 

  rewind(f);
  */

void sortString(char * inName, char * outName)
{
  //Initiation of input file and array
  int numLine = countLine(inName);
  FILE * f = fopen(inName,"r");
  char **arr = malloc(sizeof(char *) * numLine);    //Double array

  int i;
  for(i = 0; i <  numLine; i++)
    {
      arr[i] = malloc(sizeof(char)* LINELENGTH);
    }

  int k = 0;
  while(k < numLine)
    {
      fscanf(f, "%s", arr[k]);
      k++;
    }

  fclose(f);

  //Start Output file:
  FILE *f2 = fopen(outName,"w");

  int j = 0;
  for (j=0; j < numLine; j++)
    {
      qsort(arr, numLine, sizeof(char *),cmpStr);
      fprintf (f2, "%s\n", arr[j]);
    }

  fclose(f2);

  //Start Freeing Mallocs:
  int l = 0;
  for(l=0;l< numLine;l++)
    {
      free(arr[l]);
    }

  free(arr);
}


/*
 *========================================================
 *Count the amounts of data stored in files by counting the number
 *  of the newline '\n' characters
 */

int countLine(char *inName)
{
  FILE * f = fopen(inName, "r");
  int count = 0;
  char read = 0;
  
  while ((read = fgetc(f)) != EOF )
    {
      if(read == '\n')
      count++;
    }
  fclose(f);
  return(count);
}


/*
 *COMPARE FUNCTIONS Used in qsort:
 *========================================================
 */
 /* POSSIBLE ALT cmpInt:
  const int * ia = (const int *)a;
  const int * ib = (const int *)b;
  return *ia - * ib;*/

int cmpInt( const void *a, const void *b)
{
  return ( *(int*)a - *(int*)b );
}

int cmpStr(const void *s1, const void *s2)
{
  char ** t1 = (char **)s1;
  char ** t2 = (char **)s2;
  return strcmp(*t1, *t2);
}
