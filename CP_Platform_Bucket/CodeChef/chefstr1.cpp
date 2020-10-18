#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int tot=0;
		int n;
		cin>>n;
		int s[n],i;
		for(i=0;i<n;i++)
			cin>>s[i];
		for(i=1;i<n;i++)
			tot+=(abs(s[i]-s[i-1])-1);
		cout<<tot<<endl;
	}
	return 0;
}
		

