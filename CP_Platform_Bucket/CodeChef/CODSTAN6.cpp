#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair

int main()
{
	fast;
	string s;
	cin>>s;
	map<int,int> m;
	int i,j;
	for(i=65,j=27;i<=90;i++)
		m[i]=j--;
	int sum=0;
	for(i=0;i<s.length();i++)
		sum+=m[int(s[i])];
	cout<<sum<<endl;
    return 0;
}
