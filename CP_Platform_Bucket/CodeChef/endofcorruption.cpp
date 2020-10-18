#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,i,index;
	cin>>n>>m;
	int a[n+m];
	for(i=0;i<(n+m);i++)
		cin>>a[i];
	for(i=0;i<(n+m);i++)
	{
		int t=0,max=0;
		while(a[t]!=-1)
		{
			if(a[t]>max)
			{
				max=a[i];
				index=i;
			}
			t++;
		}
		if(a[t]==-1)
		{
			cout<<max<<endl;
			a[index]=0;
			a[t]=0;
		}
	}
	return 0;	
}
	
