#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair
vector<int> u,v;
map<int,int> a,b;

int check(int p,int q)
{
	if((a[p]%2!=0)||(b[q]%2!=0))
		return -1;
	ll t= (min((a[p]/2),(b[q]/2))*min(p,q));
	int y=min(a[p],b[q]);
	a[p]-=y;
	b[q]-=y;
	return t;
}
	
int main()
{
	fast;
	
    ll t;
    cin>>t;
    while(t--){
		ll n,i,q=0,sum=0,flag=0;
		cin>>n;
		
		for(i=0;i<n;i++){
			ll z;
			cin>>z;
			u.pb(z);
		}
		for(i=0;i<n;i++){
			ll z;
			cin>>z;
			v.pb(z);	
		}
		sort(u.begin(),u.end());
		sort(v.begin(),v.end());
		
		for(auto i:u)
			a[i]++;
		for(auto i:v)
			b[i]++;
		
		for(auto i:u)
		{
			if(a[i]==b[i]){
				a.erase(i);
				b.erase(i);
			}
		}
			
		for(i=0;i<n;i++)
		{
			flag=0;
			if(u[i]!=v[i])
			{
				q=check(u[i],v[i]);
				if(q==-1){
					flag=1;
				}
				else{
					for(ll k=i;k<n-1;k++){				
						if(u[k+1]!=u[k])
							break;
						else if(v[k+1]!=v[k])
							break;
						else
							i++;
						//cout<<"1hi"<<endl;
					}
				}
			}
			else{
				//cout<<"2hi"<<endl;
				a[u[i]]--;
				b[v[i]]--;
			}
			
			sum+=q;
			//cout<<"i="<<i<<" sum= "<<sum<<endl;
			if(flag==1)
				break;
		}
		if(flag==1)
			sum=q;
		cout<<sum<<endl;
		a.clear();
		b.clear();
		u.clear();
		v.clear();
	}
    return 0;
}



