#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,x,y;
		cin>>n>>m>>x>>y;
		int ans=0,num,a,b;
		num=n*m;
		if(n==m&&n==1)
			cout<<x<<endl;
		else{
			if(num%2==0)
			{
				a=num/2;
				b=num/2;
			}
			else {
				a=int(num/2)+1;
				b=int(num/2);
			}
			if(x>y)
				ans=a*y;
			else if(x<y)
			{
				if(y<2*x)
					ans=x*a+(y-x)*b;
				else 
					ans=x*a+x*b;
			}
			else
				ans=a*x;
			cout<<ans<<endl;
		}
	}
	return 0;
}
