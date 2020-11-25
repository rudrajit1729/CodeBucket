#include<iostream>
using namespace std;

int solve(int n)
{
	int choices = 0, i;
	for (i=1;i<=n/2;i++)
	{
		if ((n-i)%i==0)
			{
				choices++;
			} 
	}
	return choices;
}

int main()
{
	int n;
	cin>>n;
	cout<<solve(n);
}