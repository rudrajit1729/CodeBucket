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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll a[n],b[n],i;
		for(i=0;i<n;i++)
			cin>>a[i];
		for(i=0;i<n;i++)
			cin>>b[i];
		sort(a, a+n);
		sort(b, b+n);
		ll sum=0;
		for(i=0;i<n;i++)
			sum+=min(a[i],b[i]);
		cout<<sum<<endl;
	}
    return 0;
}
