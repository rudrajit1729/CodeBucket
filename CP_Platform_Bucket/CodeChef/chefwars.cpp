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
		int h,p,ans=-1;
		cin>>h>>p;
		if(p>=(h/2))
			ans=1;
		else{
			while(true){
				if(h<=0){
					ans=1;
					break;
				}
				else if(p<=0){
					ans=0;
					break;
				}
				h-=p;
				p=floor(p/2);
			//	cout<<"h= "<<h<<" p= "<<p<<endl;
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}
