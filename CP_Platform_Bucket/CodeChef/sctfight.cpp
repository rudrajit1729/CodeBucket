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
		int n,i;
		ll maxt=0;
		cin>>n;
		vector<ll> l;
		for(i=0;i<n;i++){
			ll x;
			cin>>x;
			l.pb(x);
		}
		unordered_map<ll,ll> m;
		for(auto u:l)
			m[u]++;
		for(auto u:l)
			maxt=max(maxt,m[u]);
		cout<<maxt<<endl;
		m.clear();
	}
		
		
    return 0;
}
