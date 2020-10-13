#include<stdio.h>
#include<stdlib.h>

void split(int *,int ,int);
void merge(int*,int,int ,int);

int main()
{
	int *ar,n,i=0;
	printf("\nEnter capacity:");
	scanf("%d",&n);
	ar=(int*)malloc(sizeof(int));
	printf("\nEnter elements:");
	for(i=0;i<n;i++)
	scanf("%d",&ar[i]);
	printf("\nSorted array:");
	split(ar,0,n-1);
	for(i=0;i<n;i++)
	printf("%3d",ar[i]);
}

void split(int *ar,int l,int r)
{
	int mid;
	if(l<r)
	{
		mid=(l+r)/2;
		split(ar,l,mid);
		split(ar,mid+1,r);
		merge(ar,l,mid,r);
	}
}

void merge(int *ar,int l,int mid,int r)
{
	int i=l,j=mid+1,k=0;
	int temp[r-l+1];
	while(i<=mid && j<=r)
	{
		if(ar[i]<=ar[j])
		temp[k++]=ar[i++];
		else
		temp[k++]=ar[j++];
	}
	while(i<=mid)
	temp[k++]=ar[i++];
	while(j<=r)
	temp[k++]=ar[j++];
	for(i=l,k=0;i<=r;i++,k++)
	ar[i]=temp[k];
}
