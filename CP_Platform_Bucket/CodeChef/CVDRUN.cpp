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
		int n,k,x,y;
		cin>>n>>k>>x>>y;
		int a[n+1],i,j,next=0,flag=0,aux;
		for(i=0;i<=n;i++)
			a[i]=0;
		a[x]=1;
		aux=x;
		string ans;
		if(x==y)
			ans="YES";
		else{
			while(true){
				next=(x+k)%n;
				x=next;
				cout<<next<<endl;
				a[next]=1;
				if(next==aux){
					if(a[y]==1)
						ans="YES";
					else
						ans="NO";
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}
