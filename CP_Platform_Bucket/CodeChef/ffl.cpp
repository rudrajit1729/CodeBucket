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
		int n,s;
		cin>>n>>s;
		int p[n],a[n],minz=999,mino=999,i;
		for(i=0;i<n;i++)
			cin>>p[i];
		for(i=0;i<n;i++)
			cin>>a[i];
		vector<pair<int,int>> v;
		for(i=0;i<n;i++)
			v.pb(make_pair(p[i],a[i]));
		sort(v.begin(),v.end());
		for(auto u:v){
			if(u.second==0){
				minz=u.first;
				break;
			}
		}
		for(auto u:v){
			if(u.second==1){
				mino=u.first;
				break;
			}
		}		
		int tot=minz+mino;
		if(tot<=(100-s))
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
		v.clear();
	}
    return 0;
}
