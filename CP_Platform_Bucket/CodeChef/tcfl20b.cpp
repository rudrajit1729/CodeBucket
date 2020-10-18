#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll time;
        string s1;
        map<ll,string> m;
        for(int i=0;i<n;i++){
            cin>>s1;
            cin>>time;
            m[time]=s1;
        }
        for(auto i=m.begin();i!=m.end();i++){
            cout<<i->second<<endl;
        }
    }
}
