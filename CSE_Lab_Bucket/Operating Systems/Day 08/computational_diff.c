#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	int p, i = 5;
	p = fork();
	
	if(p ==0){
		printf("Child Process %d\n", ++i);
	}
	if(p > 0)
		printf("Parent Process %d\n", i);
	else(p < 0)
		printf("Error\n");
	return 0;
}