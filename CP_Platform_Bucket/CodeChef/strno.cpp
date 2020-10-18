#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main() 
{
	lli t;
	cin>>t;
	while(t--){
	    lli count=0,x,k,i;
	    cin>>x>>k;
	    while(x%2==0){
	        count++;
	        x=x/2;
	    }
	    cout<<x<<endl;
	    for(i=3;i*i<=x;i=i+2){
	        while(x%i==0){
	            x=x/i;
	            count++;
	        }
	    }
	    if(x>2)
	    	count++;
	    if(count>=k)
	    	cout<<"1\n";
	    else
	    	cout<<"0\n";
	}
	return 0;
}
