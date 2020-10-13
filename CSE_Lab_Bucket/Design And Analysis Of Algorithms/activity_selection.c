//Activity Selection Problem

//Import libraries
#include <stdio.h>
#include <stdlib.h>

//Define structure pair having 3 values start time, end time & index
typedef struct pair{
		int start, end, ind;
}pair;

//Swap function
void swap(pair *p1, pair *p2)
{
		pair temp = *p1;
		*p1 = *p2;
		*p2 = temp;
}

//Sort function - Insertion sort. Sorts in non decreasing order of end times
void sort(pair *ar, int n)
{
	int i, d, temp;
	for(i=1; i<n; i++)
	{
		d = i;
		while (d > 0 && ar[d].end < ar[d-1].end)
		{
			swap(&ar[d], &ar[d-1]);
			d--;
		}
	}
}


int main()
{
	int max, lastend, sum = 0, count = 0, n,i, ind;pair *data;

	//Value Input
	printf("\nEnter limit:");
	scanf("%d", &n);
	data = (pair*)malloc(n*sizeof(pair));

	printf("\nEnter start times:");
	for(i=0; i<n; i++)
	{
		data[i].ind = i+1;
		scanf("%d", &(data[i].start));
	}

	printf("\nEnter end times:");
	for(i=0; i<n; i++)
		scanf("%d", &(data[i].end));

	//Algorithm
	sort(data, n);

	printf("\nIndex=%d start = %d end = %d",data[0].ind,data[0].start,data[0].end);
	lastend = data[0].end;
	for (i=1;i<n;i++)
	{
		if (data[i].start>lastend)
		{
			printf("\nIndex=%d start = %d end = %d",data[i].ind,data[i].start,data[i].end);
			lastend = data[i].end;
		}

	}
	printf("\n");
	
/*
	//printing
	printf("\nIndex:\t\t");
	for(i=0; i<n; i++)
	{
		printf("%d\t",data[i].ind);
		//sum += data[i].p;
	}
	printf("\nStart times:\t");
	for(i=0; i<n; i++)
	{
		printf("%d\t",data[i].start);
		//sum += data[i].p;
	}
	printf("\nEnd times:\t");
	for(i=0; i<n; i++)
	{
		printf("%d\t",data[i].end);
		//sum += data[i].p;
	}

	//printf("\nMax Profit := %d\n", sum);

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
