#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n],mind=999,ans[n]={0},x=0,diff=0;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]==1)
				ans[x++]=i;
		}
		for(i=0;i<x-1;i++)
		{
			diff=ans[i+1]-ans[i];
			mind=min(mind,diff);
		}
		if(mind<6)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
}
			
		
	

			
			
			
				
				
					
			
			
			
