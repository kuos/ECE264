
/**
 * The ENTIRE assignment should be completed within this file
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <pthread.h>

#include "pa06.h"

/**
 * Read a uint128 from a string.
 * This function is provided for your convenience.
 */

typedef struct _object {
  uint128 value;
  uint128 up_bd;
  uint128 low_bd;
  int prime;
} Object;



uint128 alphaTou128(const char * str)
{
    uint128 ret = 0;
    while(*str >= '0' && *str <= '9') 
      {
	ret *= 10; // "left-shift" a base-ten number
	ret += (*str - '0'); // add in the units
	++str;
      }
    return ret;
}

/**
 * The caller is responsible for freeing the result 
 */


char * u128ToString(uint128 value)
{
  int length = 0;

  uint128 temp = value;
  uint128 temp2 = value;


  while (temp != 0)
    {
      temp /= 10;
      length ++;
    }

  char * str = malloc(sizeof(char)*(length+1));
  
  str[length] = '\0';
  
  int i;

  for(i = length-1; i >= 0; i--)
    {
      str[i] = (temp2  % 10) + '0';
      temp2 /= 10;
    }

  return str;
}




/**
 * Test is 'value' is prime.
 * 'n_threads' is the number of threads to create to complete this computation.
 * Return TRUE of FALSE.
 * 
 * LEAK NO MEMORY
 *
 * Good luck!
 */

//pthread_create(&th, &attr, func, object);

int primalityTestParallel(uint128 value, int n_threads)
{
  //Test if the value is 2 or 1:
  if(value == 2 || value == 1)
    {
      return TRUE;
    }

  //Test if divisible by even:
  if (value % 2 == 0)
    {
      return FALSE;
    }

  //Initialize threads and attr for later use:
  pthread_t * thread = malloc(sizeof(pthread_t) * n_threads);
  pthread_attr_t *  attr = malloc(sizeof(pthread_attr_t) * n_threads);

  //pthread_attr_init(&attr);
  //pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
 

  //Getting the max value for testing,
  //Dividing up the chunks for threads.
  int max = floor(sqrt(value));
  uint128 chunk_size = (max + n_threads)/ n_threads;

  //Creating a object array:
  
  Object * object = malloc(sizeof(Object)*n_threads);

  uint128 i;
  int created;

  for(i = 0; i < n_threads; i++)
    {
      object[i].value = value; 
      object[i].low_bd  = i * chunk_size;
      object[i].up_bd = (i+1)*chunk_size;
      
      //If lower bound less than 3, make it 3
      //If lower bound even, make it odd
      if(object[i].low_bd  < 3)
	{
	  object[i].low_bd = 3;
	}
      if(object[i].low_bd % 2 == 0)
	{
	  object[i].low_bd ++;
	}

      pthread_attr_init(&attr[i]);
      
      //Create the actual thread, pass in function and object
      created = pthread_create(&thread[i], &attr[i], primeTest, (void *) &object[i]);

      if (created)
	{
	  printf("ERROR, Thread not created properly!!");
	  return 0;
	}
    } 
  
  //pthread_attr_destroy(&attr);

  //Join the threads:
  int j;
  int joined;
  //void * status;

  for(j = 0; j < n_threads; j++)
    {
      joined = pthread_join(thread[j], NULL);
      /* if(joined != 0)
	{
	  printf("EROOR, Thread not joined properly!!");
	  return 0;
	}
      */
    }

  int result;

  result = 1;
  int k = 0;
  for(k=0; k <n_threads;k++)
    {
      if(object[k].prime != 1)
	{
	  result = 0;
	  k = n_threads;
	}
    }

  free(thread);
  free(attr);
  free(object);
 
  return result;
}


/*FROM WEBPAGE:
You will need to modify this function to make it
parallel. Furthermore, this function deals with puny "long int"
numbers. We'll want more juice than that. So you will also have to
modify this function to use 128 bit integers. */

/*If you want to test if a number is divisible (exactly) by numbers 
in the range [0..n], then you can split this range into chunks, 
and test each chunk in a separate thread. If /any/
chunk of the computation finds a factor, then the number is not prime.*/


void * primeTest(void * obj)
{
  Object * oinfo = (Object *)obj;
  uint128 i;

  for (i = oinfo->low_bd; i <= oinfo->up_bd; i+=2) 
    {
	if (oinfo->value % i  == 0) 
	  {
	    oinfo->prime = FALSE;
	    return NULL;
	  }
	
    }	
    oinfo->prime = TRUE;
    return NULL;
}


(*obj)->low_
