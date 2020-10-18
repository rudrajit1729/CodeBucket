#include<bits/stdc++.h>
using namespace std;
void shift(int b[],int n)
{
	int i;
	int temp=b[n];
	for(i=1;i<n;i++)
		b[i]=b[i-1];
	b[0]=temp;
}	
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,i,j,max=0,sh=0,flag=0;
		cin>>n;
		int a[n],b[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			b[i]=a[i];
			if(a[i]>max)
			{
				max=a[i];
			//	int mc=0;
			}
		//	if(a[i]==max)
				//mc++;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				if(b[j]==max)
				{
					shift(b,n);
					sh++;
				}
		}
			cout<<sh<<endl;
	}
	return 0;
}
				
	
				
				
			
			
