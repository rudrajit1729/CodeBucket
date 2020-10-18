#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m,i,n,j,count=0;
	cin>>m;
	int a[m];
	for(i=0;i<m;i++)
		cin>>a[i];
	cin>>n;
	int b[n];
	for(j=0;j<n;j++)
	{
		int bb;
		cin>>bb;
		b[count++]=a[bb-1];
		for(i=bb-1;i<m;i++)
			a[i]=a[i+1];
		m--;
	}
	for(i=0;i<n;i++)
		cout<<b[i]<<endl;
	return 0;
}
			
		
	
	
