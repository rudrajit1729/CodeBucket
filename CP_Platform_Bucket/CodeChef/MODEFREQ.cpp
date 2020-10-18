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
		map<int,int>m,v;
		int i,ma=-1,mi=INT_MAX;
		for(i=0;i<n;i++){
			int x;
			cin>>x;
			m[x]++;
		}
		for(auto u:m){
			v[u.second]++;
		}
		for(auto u:v){
			ma=max(ma,u.second);
		}
		for(auto u:v){
			if(u.second==ma)
				mi=min(mi,u.first);
		}
		cout<<mi<<endl;
		m.clear();
		v.clear();
	}
    return 0;
}
