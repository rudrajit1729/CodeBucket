#include<iostream>
using namespace std;

int solve(int n, int k)
{
	int i;
	for(i=0;i<k;i++)
	{
		if (n%10==0)
			n /= 10;
		else
			n--;
	}
	return n;
}
int main()
{
	int n, k;
	cin >> n >> k;
	cout << solve(n, k);
}