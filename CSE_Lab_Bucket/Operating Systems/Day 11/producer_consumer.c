#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#define BUFFER_MAX 10

pthread_mutex_t mutex;
sem_t full, empty;
int buffer[BUFFER_MAX];
int count;
pthread_t ptid, ctid;

void *producer(void *);
void *consumer(void *);

// Utility Function - Inserts item in buffer
void insert_item(int item){
        buffer[count++] = item;
}

// Utility Function - Removes item from buffer
int remove_item(){
        return (buffer[count--]);
}

// Spin up system & initialize semaphores
void initialize(){
        pthread_mutex_init(&mutex,NULL);
        sem_init (&full,1,0);
        sem_init (&empty,1,BUFFER_MAX);
        count = 0;
}

// Producer Module
void *producer(void *param){
        while(1){
                // Produce item and insert when access found
                int item, waittime;
                waittime = rand()%5;
                sleep(waittime);
                item = rand()%10;
                sem_wait(&empty);
                pthread_mutex_lock(&mutex);
                printf("Producer produced item %d\n",item);
                insert_item(item);
                pthread_mutex_unlock(&mutex);
                sem_post(&full);
        }
}

// Consumer module
void *consumer(void *param){
        while(1){
                // Consume item
                int item, waittime;
                waittime = rand()%3;
                sleep(waittime);
                sem_wait(&full);
                pthread_mutex_lock(&mutex);
                item = remove_item();
                printf("Consumer consumed %d\n",item);
                pthread_mutex_unlock(&mutex);
                sem_post(&empty);
        }
}

int main(){
        // Create system
        initialize();
        // Create producer and consumer threads
        pthread_create(&ptid,NULL,&producer,NULL);
        pthread_create(&ctid,NULL,&consumer,NULL);
        pthread_join(ptid,NULL);
        pthread_join(ctid,NULL);
        return 0;
}