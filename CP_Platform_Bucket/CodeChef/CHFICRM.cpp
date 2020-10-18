#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,c[2]={0},i,flag=0;
		cin>>n;
		for(i=0;i<n;i++)
		{
			int coin;
			cin>>coin;
			if(coin==5)
				c[0]+=1;
			else if(coin==10)
				c[1]+=1;
			if(coin==10&&c[0]<=0)
				flag=1;
			else if(coin==15&&(c[1]<=0&&c[0]<2))
				flag=1;
			if(coin==10&&c[0]>=1)
				c[0]-=1;
			else if(coin==15&&c[1]>=1)
				c[1]-=1;
			else if(coin==15&&c[0]>=2)
				c[0]-=2;
		}
		if(flag)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
}
				
