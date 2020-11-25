#include<iostream>
using namespace std;

int solve(int n)
{
	int ar[]= {100,20,10,5,1};
	int i = 0, bills = 0;
	for(i=0;i<5;i++)
	{
		while (n-ar[i]>=0)
		{
			bills += 1;
			n -= ar[i];
			if(n==0)
				break;
		}
	}
	return bills;
}

int main()
{
	int n;
	cin>>n;
	cout<<solve(n);
	return 0;
}