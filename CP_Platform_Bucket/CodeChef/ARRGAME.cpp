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
		string ans;
		cin>>n;
		int a[n],i;
		for(i=0;i<n;i++){
			cin>>a[i];
		}
		vector<int>v;
		for(i=0;i<n;i++){
			if(a[i]==0){
				v.pb(i);
			}
		}
		if(!v.size()){
			ans="No";
		}
		else if(v.size()==1){
			ans="Yes";
		}
		else{
			int k=1,oo=0,ee=0;
			for(i=1;i<v.size();i++){
				int flag=0;
				if(v[i]-v[i-1]>1){
					if(k%2==1)
						oo=max(oo,k);
					else
						ee=max(ee,k);
					k=1;
					flag=1;
				}
				else{
					k++;
					if((!flag)&&(i==(v.size()-1))){
						if(k%2==1)
							oo=max(oo,k);
						else
							ee=max(ee,k);
					}
				}
			}
			if(oo>(2*ee))
				ans="Yes";
			else
				ans="No";
		}
		cout<<ans<<endl;
		v.clear();
	}
    return 0;
}
