#include <iostream>
#include <pthread.h>

using namespace std;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t full =    PTHREAD_COND_INITIALIZER;
pthread_cond_t empty =   PTHREAD_COND_INITIALIZER;


const int mymax = 10;
//char buf[mymax];
int num;
int ccid = 0;
int ppid = 0;


void consume()
{
    --num;
}

void *consumer(void *p)
{
int id = ++ccid;
while (1)
  {
    sleep(3);
    pthread_mutex_lock(&mutex);
    while (num <= 0)
        pthread_cond_wait(&empty, &mutex);
    consume();
    cout<< "conumer thread "<<id<<" consue, left num="<<num<<endl;
    pthread_cond_signal(&full);
    pthread_mutex_unlock(&mutex);
    
  }
}

void produce()
{
    ++num;
}

void *producer(void *p)
{
int id = ++ppid;
while(1)
  {    
    sleep(1);
    pthread_mutex_lock(&mutex);
    while (num >= mymax)
        pthread_cond_wait(&full, &mutex);
    produce();
    cout<< "producer thread "<<id<<" produce, left num="<<num<<endl;
    
    pthread_cond_signal(&empty);
    pthread_mutex_unlock(&mutex);
  }
}

int main()
{
    pthread_t pid1,pid2,cid1,cid2;
    pthread_create(&pid1, NULL, producer, NULL);
    pthread_create(&pid2, NULL, producer, NULL);
    pthread_create(&cid1, NULL, consumer, NULL);
    pthread_create(&cid2, NULL, consumer, NULL);
    pthread_join(pid1, NULL);
    pthread_join(pid2, NULL);
    pthread_join(cid1, NULL);
    pthread_join(cid2, NULL);
    return 0;
} 
