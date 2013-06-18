/*
 * Please fill the functions in this file.
 * You can add additional functions. 
 *
 * Hint: 
 * You can write additonal functions.
 *
 * You may create additional arrays if needed.  The maximum size
 * needed is specified by MAXLENGTH in pa01.h.
 */

#include "pa01.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * =================================================================
 * This function prints all partitions of a positive integer value
 * See the file "expected/example-output" for the output specification
 */


void printPartition(int *part, int length)
{
  int index = 0;
  printf("= ");
  for (index = 0; index <length -1; index++)
    {
      printf(" %d + ",part[index]);
    }
  printf(" %d \n", part[length -1]);
}

void partition(int *result, int ind, int left)
{
  int val = 0;
  if (left == 0){
    printPartition(result, ind);
  }
  
  for (val=1;val<=left;val++){
    result[ind] = val;
    partition(result, ind + 1, left - val);
  }
}

void partitionAll(int value)
{
  int array[MAXLENGTH]={0};
  printf("partitionAll %d\n", value);
  partition(array, 0, value);
}


/*
 * =================================================================
 * This function prints the partitions that use increasing values.
 *
 * For example, if value is 5
 * 2 + 3 and
 * 1 + 4 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 3 and
 * 2 + 1 + 2 and
 * 3 + 2 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 *
 * See the file "expected/example-output" for the output specification
 */


void printIncreasing(int *part, int length)
{
  int index = 0;
  printf("= ");
  for (index = 0; index <length -1; index++)
    {
      printf("%d + ",part[index]);
    }
  printf("%d \n", part[length -1]);
}

void partition2(int *result, int ind, int left)
{
  int val = 0;
  if (left == 0)
  {
    printIncreasing(result, ind);
  }
  
  for (val=1;val<=left;val++)
    {
      result[ind] = val;
      if (ind == 0 || result[ind]> result[ind-1]) 
	//Test for index 0, and increasing values in array,
	//If not true, continue to next val.
	{
	  partition2(result,ind+1,left - val);
	}
    }  
}


void partitionIncreasing(int value)
{
  int array[MAXLENGTH]={0};
  printf("partitionIncreasing %d\n", value);
  partition2(array, 0, value);
}


/*
 * =================================================================
 * This function prints the partitions that use unique values.
 *
 * For example, if value is 5
 * 2 + 3 and
 * 3 + 2 and
 * 1 + 4 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 3 and
 * 2 + 1 + 2 are invalid partitions.
 *
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 *
 * See the file "expected/example-output" for the output specification
 */


void printUnique(int *part, int length)
{
  int index = 0;
  printf("= ");
  for (index = 0; index <length -1; index++)
    {
      printf(" %d + ",part[index]);
    }
  printf(" %d \n", part[length -1]);
}

void partition3(int *result, int ind, int left)
{
  int val = 0;
  int i;

  if (left == 0){
    printUnique(result, ind);
  }
  
  for (val=1;val<=left;val++)
    {
      result[ind] = val;
    
      int unique = 1; //Initialize a test number for uniqueness

      for(i=0;i<ind;i++)
	{
	  if(result[i]==val)
		{
		  unique = 0;
		}
	}

      if(unique == 1) 
	//If the array is unique, then recurs
	//If not, continue to next val
	{
	  partition3(result,ind+1,left - val);	 
	}
    }
}

void partitionUnique(int value)
{
  int array[MAXLENGTH]={0};
  printf("partitionUnique %d\n", value);
  partition3(array,0,value);
}




/*
 * =================================================================
 * See the file "expected/example-output" for the output specification
 */



void change(char *x, char *y) //Switching elements in the array
{
    char temp = *x;
    *x = *y;
    *y = temp;
}


//From Exam I (recursive Permute Function with starting Index)

void recursivePermute ( char * charset , int ind , int length )
{
  int i;
  if ( ind == length ) //If at the end, print the characters with space
    {  
      for ( i = 0; i < length ; i++)
	{
	  printf ("%c ", charset[i]);
	}
      printf ("\n");
    }
  for ( i = ind ; i < length ; i ++)
    {
      change(&charset[i] , & charset[ind]);
      recursivePermute (charset,ind + 1 ,length);
      change(&charset[i] ,&charset[ind]);
    }
}

void permute(char * charset, int len)
{
  printf("permute %d\n", len);
  recursivePermute(charset,0,len);
}

