#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair
const int N=100;
void transpose(int st,int en,int m[][N],int ma[][N]){
	int i,j,k;
	for(i=st;i<=en;i++){
		for(j=st;j<=en;j++){
			int temp=m[i][j];
			m[i][j]=ma[j][i];
			ma[j][i]=temp;
		}
	}
}

int main()
{
	fast;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int i,j,m[N][N],ma[N][N],count=0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++){
				cin>>m[i][j];
				ma[i][j]=m[i][j];
			}
		for(i=n-1;i>=0;i--)
			if(m[0][i]!=(i+1)){
				transpose(0,i,m,ma);
				++count;
			}
		cout<<count<<endl;
		
	}
    return 0;
}
