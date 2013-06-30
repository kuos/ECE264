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
  int numLine;                   //The number of lines in the file
  int *arr;                      //The array of data using malloc
 
  numLine = countLine(inName);
  arr = malloc(sizeof(int)*numLine);
  
  FILE *f = fopen(inName, "r");
  if (f == NULL)
    {
      printf("Error Opening file.\n");
    }

  int i = 0;
  while(i <= numLine)
    {
      fscanf(f, "%d",&arr[i]);
      i++;
    }

  qsort(arr, numLine, sizeof(int),cmpInt);

  FILE *f2 = fopen(outName, "w");
  if (f2 == NULL)
    {
      printf("Error Opening file.\n");
    }
  
  int j = 0;
  for (j=0; j < numLine; j++)
    {
      fprintf (f2, "%d\n",arr[j]);
    }
   
  fclose(f);
  fclose(f2);
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


int cmpInt( const void *a, const void *b)
{
  /*const int * ia = (const int *)a;
  const int * ib = (const int *)b;
  return *ia - * ib;*/
  return ( *(int*)a - *(int*)b );
}

int cmpStr(const void *s1, const void *s2)
{
   return strcmp(* (char*const*)s1, *(char*const*)s2);
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

void sortString(char * inName, char * outName)
{
  char **arr;    //Double array
  int numLine = countLine(inName);

  arr = malloc(sizeof(char*) * numLine);

  int i = 0;
  for(i = 0; i < numLine; i++)
    {
      arr[i] = malloc(sizeof(char)*LINELENGTH);
    }
  

  FILE *f;
  f = fopen(inName,"r");

  int k = 0;
  while(!feof(f))
    {
      fscanf(f, "%s", arr[k]);
      printf("%s",arr[k]);
      k++;
    }

  FILE *f2;
  f2 = fopen(outName,"w");

  int j = 0;
  for (j=0; j < numLine; j++)
    {
      qsort(arr[j], numLine, sizeof(char),cmpStr);
      fprintf (f2, "%s\n",arr[j]);
    }
   
}
 
