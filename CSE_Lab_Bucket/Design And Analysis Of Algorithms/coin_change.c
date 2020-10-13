// Coin Change problem - Greedy Approach

// Importing the Libraries
#include <stdio.h>
#include <stdlib.h>

void sort(int *ar, int n)
{
	int i = 0, d,temp;
	for (i=1;i<n;i++)
	{
		d=i;
		while (d>0 && ar[d]>ar[d-1])
		{
			temp = ar[d];
			ar[d] = ar[d-1];
			ar[d-1] = temp;
			d--;
		}
	}
}


void getans(int *ar, int n)
{
	int i;
	printf("\nSolution set = {");
	for(i=0; i<n; i++)
	{
		if (ar[i]!=0)
			printf("%d,",ar[i]);
	}
	printf("}\n");
}

int main()
{
	int *coin, n, i, k=0, lim, sum = 0, *sol;

	printf("\nEnter amount required:");
	scanf("%d",&lim);
	printf("\nEnter no of coins:");
	scanf("%d",&n);

	coin = (int*)malloc(n*sizeof(int));
	sol = (int*)malloc(n*sizeof(int));

	printf("\nEnter values:");
	for(i=0; i<n; i++)
		scanf("%d",&coin[i]);

	sort(coin, n);

	//Algorithm
	i=0;
	while (sum < lim)
	{
		if (sum + coin[i] > lim)
		{
			sum -= coin[i-1];
			sol[k-1] = 0;
		}
		if (sum + coin[i] <=lim)
		{
			sum += coin[i];
			sol[k++] = coin[i];
		}
		i++;
	}
	getans(sol,k);
}
