#include <stdio.h>
void Tower(int n,char from,char to,char aux)
{
	if(n==1)
	printf("\n%d=%c->%c",n,from,to);
	else
	{
		Tower(n-1,from,aux,to);
		printf("\n%d=%c->%c",n,from,to);
		Tower(n-1,aux,to,from);
	}
}

int main()
{
	int n;
	printf("\nEnter no. of disks:");
	scanf("%d",&n);
	Tower(n,'A','C','B');
}
