#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,i,tot=0;
		cin>>n>>k;
		for(i=0;i<n;i++)
		{
			int p;
			cin>>p;
			if(p>k)
				tot+=p-k;
		}
		cout<<tot<<endl;
	}
	return 0;
}
		
