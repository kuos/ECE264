What is atomic operation?
Example of atomic operation?
why is it important that some operations are atomic?

atomic = once start, it can not be divided

a = 5;
a++

read a
increment
write a

Two or use threads share data, data change is not atomic -> problems

a = 4
  t1 a++;
t2 a++;

Synchronization:

t1 modifying shared data (read/write)
t2 should be no change/read shared data



  a = 4;

t1 = a++;
t2 =  x = a;
      y = a;

Which one is it gonna read? 4 or 5?

mutually exclusive (atomic)



lock -> protected shared data

     pthread_mutex_t * mutex;


pthread_mutex_lock (mutex);

//critical section:

unlock (mutex);


//Amdahl's law: (Diminishing return)
// Your original program has 99% time that can be shortened by parallelization and 1% cannot.
// What is the maximum performance improvement by parallelization?


100 seconds
99 second -> parallelization -> shorter
1 second -> cannot


100 times 100sec/1sec
if a program can be divided into two parts:

parallel p
sequential 1-p
use k threads

execution time 1 time unit

new p/k+(1-p)

performance improvement: 1/(p/k+(1-p))

if k is very large, then your performance:
  1/(1-p)

Example

p = 99%
1-p = 1%

  more K (diminishing return)
