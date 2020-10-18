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
		int n,i,count=0;
		cin>>n;
		unordered_map<int,int>m;
		for(i=0;i<n;i++){
			int x;
			cin>>x;
			if((m[x]!=1)&&(x!=0)){
				m[x]++;
				++count;
			}
		}
		cout<<count<<endl;
		m.clear();
	}
    return 0;
}
