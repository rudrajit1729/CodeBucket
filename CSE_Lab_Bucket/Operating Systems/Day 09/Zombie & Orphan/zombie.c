#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	int p;

	p = fork();

	if(p == 0){
		printf("Child Process\n");
	}
	else if(p > 0){
		printf("Parent Process\n");
		while(1){
		};
	}
	return 1;
}