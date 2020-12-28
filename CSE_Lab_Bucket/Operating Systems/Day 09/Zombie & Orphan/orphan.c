#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	int p;
	p = fork();
	if(p == 0){
		printf("Child Process with praent id: %d\n", getppid());
		sleep(5);
		printf("Orphan Process with pid: %d and parent id: %d\n", getpid(), getppid());
	}
	else if(p > 0)
		printf("Parent Process with pid: %d\n", getpid());
	return 1;
}