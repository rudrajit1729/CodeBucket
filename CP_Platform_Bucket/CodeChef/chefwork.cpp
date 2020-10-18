
#include<bits/stdc++.h>
struct auth{
	int c[100000],t[100000];
};
using namespace std;
int main()
{
	int n;
	cin>>n;
	struct auth a;
	int i,j,temp;
	for(i=0;i<n;i++)
		cin>>a.c[i];
	for(i=0;i<n;i++)
		cin>>a.t[i];	
	for(i=0;i<n-1;i++)
	{
		int swap=0;
		for(j=0;j<n-i-1;j++)
		{
			if(a.c[j]>a.c[j+1])
			{
				temp=a.c[j];
				a.c[j]=a.c[j+1];
				a.c[j+1]=temp;
				temp=a.t[j];
				a.t[j]=a.t[j+1];
				a.t[j+1]=temp;
				
				swap=1;
			}
		}
		if(swap==0)	
			break;
	}		
	int m1=999999,m2=999999,s=999999;
	for(i=0;i<n;i++)
	{
		if(a.t[i]==1)
		{
			m1=a.c[i];
			break;
		}
	}
	for(i=0;i<n;i++)
	{
		if(a.t[i]==2)
		{
			m2=a.c[i];
			break;
		}
	}
	for(i=0;i<n;i++)
	{
		if(a.t[i]==3)
		{
			s=a.c[i];
			break;
		}
	}
	if(s<(m1+m2))
		cout<<s<<endl;
	else
		cout<<m1+m2;
	return 0;
}
