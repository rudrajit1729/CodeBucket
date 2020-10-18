#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,i;
		cin>>n;
		int x=0,y=0;
		char s[n];
		cin>>s[0];
		switch(s[0])
			{
				case 'L':x-=1;break;
				case 'R':x+=1;break;
				case 'U':y+=1;break;
				case 'D':y-=1;break;
			}
		for(i=1;i<n;i++)
		{
			cin>>s[i];
			if(s[i]==s[i-1])
			{	
				switch(s[0])
				{
					case 'L':x-=1;break;
					case 'R':x+=1;break;
					case 'U':y+=1;break;
					case 'D':y-=1;break;
				}
			}
			else
			{
				switch(s[i])
				{
					case 'L':x-=1;break;
					case 'R':x+=1;break;
					case 'U':y+=1;break;
					case 'D':y-=1;break;
				}
			}		
		}
		cout<<x<<" "<<y<<endl;
	}
	return 0;
}
