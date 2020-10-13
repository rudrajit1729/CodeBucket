#include <stdio.h>
#include<stdlib.h>
void qsort(int *ar,int low,int high)
{
	int i=low,j=high,temp,pivot=ar[(low+high)/2];
	while(i<=j)
	{
		while(ar[i]<pivot)
		i++;
		while(ar[j]>pivot)
		j--;
		if(i<=j)
		{
			temp=ar[i];
			ar[i]=ar[j];
			ar[j]=temp;
			i++;
			j--;
		}
	}
	if(low<j)
	qsort(ar,low,j);//sort lower half
	if(i<high)
	qsort(ar,i,high);
}
int main()
{
	int n=5,*ar,i;
	printf("\nEnter capacity\n");
	scanf("%d",&n);
	ar=(int*)malloc(n*sizeof(int));
	printf("\nEnter the elements\n");
	for(i=0;i<n;i++)
	scanf("%d",&ar[i]);
	printf("\nThe sorted array :\n");
	qsort(ar,0,n-1);
	for(i=0;i<n;i++)
	printf("%3d",ar[i]);
}
