#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	int p;
	p = fork();
	// Fork returns 0 on successful invocation
	// 0, > 0, < 0 -- successful creation of child, unsuccessful creation of child, error
	if(p ==0){
		printf("%d\n", getpid()); // Child pid
		printf("%d\n", getppid()); // Parent pid
	}
	return 0;
}