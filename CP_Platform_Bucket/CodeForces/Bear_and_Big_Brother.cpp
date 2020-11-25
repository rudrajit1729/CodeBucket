#include<iostream>
using namespace std;

int solve(int a, int b)
{
	int years = 0;
	while(a<=b)
	{
		years +=1;
		a = a*3;
		b = b*2;
	}
	return years;
}
int main()
{
	int a, b;
	cin>>a>>b;
	cout<<solve(a, b);
}