#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int n,k;
		cin>>n>>k;
		long long int d[n],i;
		for(i=0;i<n;i++)
			cin>>d[i];
		queue<int> q;	
		for(i=0;i<n;i++)
		{
			if(d[i]%k==0)
				q.push(1);
			else
				q.push(0);
		}
		for(i=0;i<n;i++)
		{
			cout<<q.front();
			q.pop();
		}
		cout<<endl;
	}
	
	return 0;
}
				
	
