#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* threadFunction(void* args){
	int i;
	for(i=1;i<=5;++i)
	{
	printf("I am new thread.\n");
	sleep(1);
	}
}

int main(){
	pthread_t id;
	int res, i;
	res=pthread_create(&id,NULL,&threadFunction,NULL);
	
	if(res==0){
	printf("Thread created successfully.\n");
	}

	else{
	printf("Thread not created.\n");
	return 0;
	}
	
	for(i=1;i<=2;++i){
	printf("I am main thread.\n");
	sleep(1);
	}
	return 0;
}
// To compile:
// $ cc thr1.c -o thr.out –lpthread
// $./thr.out