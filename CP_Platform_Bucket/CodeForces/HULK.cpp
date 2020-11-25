#include<iostream>
#include<string>
using namespace std;

void solve(int n)
{
	string a = "I hate ";
	string b = "I love ";
	string c = "that ";
	string d = "it";
	int i;
	for (i=1;i<n;i++)
	{
		if (i%2!=0)
		cout<< a << c;
		else
		cout<< b << c;
	}
	if (n%2==0)
		cout<<b <<d<<endl;
	else
		cout<<a << d<<endl;
}




int main()
{
	int n;
	cin>>n;
	solve(n);
	return 0;
}