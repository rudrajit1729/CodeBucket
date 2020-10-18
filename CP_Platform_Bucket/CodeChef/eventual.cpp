#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,i,flag=0;
		cin>>n;
		string s;
		cin>>s;
		int a[200]={0};
		for(i=0;i<n;i++)
			a[int(s[i])-97]++;
		for(i=0;i<26;i++)
		{
			if(a[i]%2!=0)
			{
				flag=1;
				break;
			}
		}
				
		if(flag==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
