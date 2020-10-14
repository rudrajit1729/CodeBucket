#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{ 
	int t;
	t=*a;
	*a=*b;
	*b=t;
}
void createheap(int a[],int n)
{ int child,parent,i;
  for(i=1;i<n;i++)
  { 	 
	 child=i;
	 do
	 { 
		parent=(child-1)/2;
		if(a[parent]<a[child])
			swap(&a[parent],&a[child]);
		child=parent;
	 }while(child!=0);
  }
}
void heapsort(int a[],int n)
{  int i,j;
	for(j=n-1;j>0;j--)
  	{ 
		swap(&a[0],&a[j]);
		createheap(a,j);
	}
}
int main()
{ int i,n,a[20];
  printf("\n Enter The Number Of Elements Of The Array : ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  { printf("\n Enter The Element %d : ",i+1);
	 scanf("%d",&a[i]);
  }
  createheap(a,n);
  heapsort(a,n);
  printf("\n The Array After Heap Sort Is : \n");
  for(i=0;i<n;i++)
  printf(" %d ",a[i]);
  getch();
  return 0;
}
