#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,p,i;
		cin>>n>>p;
		int a,cw=0,h=0;
		for(i=0;i<n;i++)
		{
			cin>>a;
			if(a>=int(p/2))
				cw+=1;
			else if(a<=int(p/10))
				h+=1;
		}
		if(cw==1&&h==2)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}
