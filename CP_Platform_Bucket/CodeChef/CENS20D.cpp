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
		cin>>n;
		int a[n],i,j,count=0;
		for(i=0;i<n;i++)
			cin>>a[i];
		if(n==1){
			cout<<"0"<<endl;
			continue;
		}
		for(i=0;i<n-1;i++){
			for(j=i+1;j<n;j++){
				if((a[i]&a[j])==a[i])
					++count;
			}
		}
		cout<<count<<endl;
		}
    return 0;
}
