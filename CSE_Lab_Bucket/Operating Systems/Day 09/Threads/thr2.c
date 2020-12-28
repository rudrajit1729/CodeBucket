#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thread_function(void *arg);
char message[] = "Hello World";

int main()
{
	int res;
	pthread_t a_thread;
	void *thread_result;
	// Thread Creation
	res = pthread_create(&a_thread, NULL, thread_function, message);
	// For Failed Creation
	if (res != 0){
	perror("Thread creation failed");
	exit(EXIT_FAILURE);
	}
	// Waiting for thread_function to execute
	printf("Waiting for thread to finish...\n");

	res = pthread_join(a_thread, &thread_result);
	// Joining thread result
	if (res != 0){
	perror("Thread join failed");
	exit(EXIT_FAILURE);
	}

	// Threads joined, executed and successful termination
	printf("Thread joined, it returned: %s\n", (char *)thread_result);
	printf("Message is now: %s\n", message);
	exit(EXIT_SUCCESS);
}

void *thread_function(void *arg)
{
	printf("Thread_function is running. Argument was: %s\n", (char *)arg);
	sleep(3);
	strcpy(message, "Bye!");
	pthread_exit("Thank you for the CPU time");
}

// To compile
// $ cc thr2.c -o thr.out –lpthread
// $./thr.out