#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		unsigned long long int n,r=0,s=0,i,x;
		cin>>n;
		for(i=n*10;i<(n+1)*10;i++)
		{
			s=0;
			x=i;
			while(x>0)
			{
				r=x%10;
				s+=r;
				x/=10;
			}
			if(s%10==0)
			{
				cout<<i<<endl;
				break;	
			}
		}
	}
	return 0;
}
		
				
			
		
