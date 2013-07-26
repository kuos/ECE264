
#include <pthread.h>

long status;
pthread_t th;
pthread_attr_t attr;

/*t is some data, probably and object*/



pthread_atti_t int (&attr);

//Main thread -> calls pthread_create
//Main -> thread created
//     -> keep doing sth else
//Later will call "join" where main thread waits for the other thread
pthread_create(&th, &attr, func, object);
       //Library
//&th is the memory allocated by operating structure to store the thread-data


pthread_join(th,&status);

void * func(void* obj)
{
  //your structure * p = (yours *job;,
  printf...;
  obj -> isPrime = 0;

}//it stores nothing
//everything is passed as an argument

//Example: http://linux.die.net/man/3/pthread_create
