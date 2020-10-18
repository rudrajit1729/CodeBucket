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
		int n,q;
		cin>>n>>q;
		string str;
		cin>>str;
		transform(str.begin(), str.end(), str.begin(), ::tolower); 
		unordered_map<char,int> m;
		for(auto u:str)
			m[u]++;
		int a[q]={0},k=0;
		while(q--){
			int c,ans=0;
			cin>>c;
			for(int i=97;i<=122;i++){
				char p=i;
				if(m[p]>c)
					ans+=(m[p]-c);
			}
			a[k++]=ans;
		}
		for(int i=0;i<k;i++)
			cout<<a[i]<<endl;
	}
	return 0;
}
