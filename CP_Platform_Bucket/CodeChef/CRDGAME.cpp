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
		int x=0,y=0;
		while(n--)
		{
			long long int a,b;
			int r;
			cin>>a>>b;
			if(a<10&&b<10)		//1
			{
				if(a>b)
					x++;
				else if(a<b) 
					y++;
				else 
				{
					x++;
					y++;
				}	
			}
			else if(a<10)		//2
			{
				int bx=0;
				while(b>0)
				{
					r=b%10;
					b=b/10;
					bx+=r;
				}
				//bx+=b;
				//cout<<"2 bx= "<<bx<<" b= "<<b<<" a= "<<a<<endl;
				if(a>bx)
					x++;
				else if(a<bx)
					y++;
				else
				{
					x++;
					y++;
				}
			}
			else if(b<10)		//3
			{
				
				int ax=0;
				while(a>0)
				{
					r=a%10;
					a=a/10;
					ax+=r;
				}
				//ax+=a;
				//cout<<"3 ax= "<<ax<<" a= "<<a<<" b= "<<b<<endl;
				if(b>ax)
					y++;
				else if(b<ax) 
					x++;
				else
				{
					x++;
					y++;
				}
			}
			else		//4
			{
				int ax=0,bx=0;
				while(a>0)
				{
					r=a%10;
					a=a/10;
					ax+=r;
				}
				//ax+=a;
				while(b>0)
				{
					r=b%10;
					b=b/10;
					bx+=r;
				}
				//bx+=b;
			//	cout<<"4 ax= "<<ax<<" a= "<<a<<endl;
			//	cout<<"4 bx= "<<bx<<" b= "<<b<<endl;
				if(ax>bx)
					x++;
				else if(ax<bx)
					y++;
				else
				{
					x++;
					y++;
				}
			}
		}
		if(x>y)
			cout<<"0 "<<x<<endl;
		else if(x<y)
			cout<<"1 "<<y<<endl;
		else
			cout<<"2 "<<x<<endl;
	}
	return 0;
}
				
				
			
