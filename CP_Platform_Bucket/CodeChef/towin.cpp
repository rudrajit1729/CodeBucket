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
		cin>>n;
		vector<ll> a;
		ll a1=0,b1=0;
		for(i=0;i<n;i++){
			ll x;
			cin>>x;
			a.pb(x);
		}
		sort(a.begin(),a.end(),greater<int>());
		if(n==1)
			cout<<"first"<<endl;
		else{
			if(n==2){
				a1+=a[0];
				b1+=a[1];
			}
			else{
				a1+=a[0];
				b1+=(a[1]+a[2]);
				for(i=3;i<n;i++){
					if(i%2!=0)
						a1+=a[i];
					else
						b1+=a[i];
				}
			}
			if(a1==b1)
				cout<<"draw"<<endl;
			else if(a1>b1)
				cout<<"first"<<endl;
			else
				cout<<"second"<<endl;	
		}
		a.clear();
	}
    return 0;
}
