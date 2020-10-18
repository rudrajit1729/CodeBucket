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
		string s;
		cin>>s;
		map<char,int> m;
		for(auto u:s)
			m[u]++;
		int u,v;
		cin>>u>>v;
		int q;
		cin>>q;
		while(q--){
			int x,y,flag1=0,flag2=0,ans=0;
			cin>>x>>y;
			int xd=u-x,yd=v-y;
			int d=abs(u-x)+abs(v-y);
			if(xd>0){
				if(m['L']>=xd){
					flag1=1;
					ans+=xd;
				}
			}
			else if(xd<0){
				if(m['R']>=abs(xd)){
					flag1=1;
					ans+=abs(xd);
				}
			}
			else if(xd==0)
				flag1=1;
			
			if(yd>0){
				if(m['D']>=yd){
					flag2=1;
					ans+=yd;
				}
			}
			else if(yd<0){
				if(m['U']>=abs(yd)){
					ans+=abs(yd);
					flag2=1;
				}
			}
			else if(yd==0)
				flag2=1;
			if(flag1&flag2==1)
				cout<<"YES "<<d<<endl;
			else
				cout<<"NO"<<endl;
			}
		}
    return 0;
}
