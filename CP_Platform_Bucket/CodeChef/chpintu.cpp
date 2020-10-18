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
		int n,b;
		cin>>n>>b;
		map<int,int> m;
		int f[n],p[n],i;
		for(i=0;i<n;i++)
			cin>>f[i];
		for(i=0;i<n;i++){
			int x;
			cin>>x;
			m[f[i]]+=x;
		}
		int minp=INT_MAX;
		for(i=0;i<n;i++){
			if(m[f[i]]<minp)
				minp=m[f[i]];
		}
		cout<<minp<<endl;
	}	
    return 0;
}
