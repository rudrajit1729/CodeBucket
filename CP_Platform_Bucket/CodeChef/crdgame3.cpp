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
		double pc,pr,win=-1;
		cin>>pc>>pr;
		double ans1,ans2,ans;
		ans1=ceil(pc/9);
		ans2=ceil(pr/9);
		
		//cout<<"ans1= "<<ans1<<" ans2= "<<ans2<<endl;
		if(ans1==ans2){
			win=1;
			ans=ans1;
		}
		else if(ans1<ans2){
			win=0;
			ans=ans1;
		}
		else{
			win=1;
			ans=ans2;
		}
	cout<<win<<" "<<ans<<endl;
	}
    return 0;
}
