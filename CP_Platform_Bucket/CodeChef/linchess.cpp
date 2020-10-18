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
		int n,k,i,flag=0,sq=0,minans=INT_MAX;
		cin>>n>>k;
		for(i=0;i<n;i++){
			int x,ans=0;
			cin>>x;
			if(k%x==0){
				ans=k/x-1;
				if(ans<minans){
					minans=ans;
					sq=x;
				}
				flag=1;
			}
		}
		if(flag==0)
			cout<<"-1"<<endl;
		else
			cout<<sq<<endl;
	}
    return 0;
}
