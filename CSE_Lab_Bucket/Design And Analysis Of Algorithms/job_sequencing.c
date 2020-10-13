//Job Scheduling Problem

//Import libraries
#include <stdio.h>
#include <stdlib.h>

//Define structure pair having 3 values profit deadline and job index
typedef struct pair{
		int p, ind, d;
}pair;

//Swap function
void swap(pair *p1, pair *p2)
{
		pair temp = *p1;
		*p1 = *p2;
		*p2 = temp;
}

//Sort function - Insertion sort. Also Returns max of elements to caller function(In this caase max deadline returned)
int sort(pair *ar, int n)
{
	int i, d, temp, max = ar[0].d;
	for(i=1; i<n; i++)
	{
		d = i;
		if (ar[i].d > max)
			max = ar[i].d;
		while (d > 0 && ar[d].p > ar[d-1].p)
		{
			swap(&ar[d], &ar[d-1]);
			d--;
		}
	}
	return max;
}

// Gets the first n jobs in ascending order of their deadlines( n is max deadline)
void getorder(pair *ar, int n)
{
		int i, d, temp, max = ar[0].d;
	for(i=1; i<n; i++)
	{
		d = i;
		while (d > 0 && ar[d].d < ar[d-1].d)
		{
			swap(&ar[d], &ar[d-1]);
			d--;
		}
	}
}

int main()
{
	int max, sum = 0, count = 0, n,i, ind;pair *data;

	//Value Input
	printf("\nEnter limit:");
	scanf("%d", &n);
	data = (pair*)malloc(n*sizeof(pair));

	printf("\nEnter profits:");
	for(i=0; i<n; i++)
	{
		data[i].ind = i+1;
		scanf("%d", &(data[i].p));
	}

	printf("\nEnter deadlines:");
	for(i=0; i<n; i++)
		scanf("%d", &(data[i].d));

	//Algorithm
	//Sort the array in descending order of deadline values.
	max = sort(data, n);
	//After getting max deadline arrange the first max number of descending values in ascending order to get job sequence
	getorder(data, max);

	//printing
	printf("\nJob Order :=\t");
	for(i=0; i<max; i++)
	{
		printf("J%d\t",data[i].ind);
		sum += data[i].p;
	}
	printf("\nMax Profit := %d\n", sum);

	//Test Input
	/*
	n = 7
	P(i) = {35, 30, 25, 20, 15, 12, 5}
	d(i) = {3, 4, 4, 2, 3, 1, 2}
	*/
	//Test Output
	/*
	Job Order := J4, J3, J1, J2
	Max Profit := 110
	*/
}
