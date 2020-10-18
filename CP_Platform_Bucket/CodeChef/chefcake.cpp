#include<bits/stdc++.h>
using namespace std;
int fact(int n)
{
	if(n==0||n==1)
		return 1;
	else
		return n*fact(n-1);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long int i,j,a[n],sum=0;
		for(i=0;i<n;i++)
			cin>>a[i];
		for(i=0;i<n;i++)
			for(j=1;j<pow(10,n);j*=10)
				sum+=j*a[i]*(fact(n)/n);
		cout<<sum<<endl;
	
	}
	return 0;
}
