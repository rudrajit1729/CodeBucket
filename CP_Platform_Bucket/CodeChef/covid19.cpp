#include<bits/stdc++.h>
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
	while(t--)
	{
		int n;
		cin>>n;
		int a[n],i,count=1,minc=10,maxc=-1;;
		for(i=0;i<n;i++)
			cin>>a[i];
		for(i=1;i<n;i++){
			if(a[i]-a[i-1]>2){
				minc=min(minc,count);
				maxc=max(maxc,count);
				count=1;
			}
			else{
				++count;
			}
		}
		if(i==n){
			minc=min(minc,count);
			maxc=max(maxc,count);
		}
		cout<<minc<<" "<<maxc<<endl;	
	}
	return 0;
}
			
