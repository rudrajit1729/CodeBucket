#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,i,j,sum=0;
		cin>>a>>b;
		int x=a,y=b,maxs=0,r1,x1,r2,y1;
		sum=a+b;
		if(a<10&&b<10)
		{
			cout<<a+b<<endl;
			continue;
		}
			r1=x%10;
			x1=x/10;
			r2=y%10;
			y1=y/10;
		int p,q,r,s,u;
		if(a<10&&b>=10)
		{
			p=y1+(r1*10+r2);
			q=r2+(y1*10+r1);
			cout<<max(max(sum,p),q)<<endl;
			continue;
		}
		else if(a>=10&&b<10)
		{
			p=(r2*10+r1)+x1;
			q=(x1*10+r2)+r1;
			cout<<max(max(sum,p),q)<<endl;
			continue;
		}
		p=(y1*10+r1)+(x1*10+r2);
		q=(r2*10+r1)+(y1*10+x1);
		r=(x1*10+y1)+(r1*10+r2);
		u=(x1*10+r2)+(y1*10+r1);
		maxs=max(sum,p);
		maxs=max(maxs,q);
		maxs=max(maxs,r);
		maxs=max(maxs,s);
		maxs=max(maxs,u);
		cout<<maxs<<endl;
		
	}
	return 0;
}
		
		
		
		
