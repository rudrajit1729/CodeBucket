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
		int i;
		string s,p,ans="",ans1="";
		cin>>s>>p;
		map<int,int> ms,ms1;
		for(auto u:s){
			ms[u-97]++;
			ms1[u-97]++;
		}
		for(auto u:p){
			ms[u-97]--;
			ms1[u-97]--;
		}
		sort(s.begin(),s.end());
		int st1=s[0]-97,st2=p[0]-97;
		if(st1<st2){
			for(i=0;i<=st2;i++){
				while(ms[i]!=0){
					ans+=char(i+97);
					--ms[i];
				}
			}
			ans+=p;
			for(i=0;i<=26;i++){
				while(ms[i]!=0){
					ans+=char(i+97);
					--ms[i];
				}
			}
		}
		else if(st2<st1){
			ans+=p;
			for(i=0;i<=26;i++){
				while(ms[i]!=0){
					ans+=char(i+97);
					--ms[i];
				}
			}
		}
		else{
			for(i=0;i<=st1;i++){
				while(ms[i]!=0){
					ans+=char(i+97);
					--ms[i];
				}
			}
			ans+=p;
			for(i=0;i<=26;i++){
				while(ms[i]!=0){
					ans+=char(i+97);
					--ms[i];
				}
			}
		}
		for(i=0;i<=26;i++){
			if(char(i+97)==p[0])
				break;
			else
				while(ms1[i]!=0){
					ans1+=char(i+97);
					--ms1[i];
				}
		}
		ans1+=p;
		for(i=0;i<=26;i++)	
			while(ms1[i]!=0){
				ans1+=char(i+97);
				--ms1[i];
			}
		if(ans<ans1)
			cout<<ans<<endl;
		else
			cout<<ans1<<endl;
	}
    return 0;
}
