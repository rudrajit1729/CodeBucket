/******************************************
* AUTHOR : Avirup Aditya *
* NICK : WarChild *
******************************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 100005
#define mod 1000000007
#define dd double
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep1(i,b) for(int i=1;i<=b;i++)
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define ff first
#define ss second
#define endl "\n"



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ios_base& scientific (ios_base& str);


  #ifndef ONLINE_JUDGE
      // for getting input from input.txt
      freopen("input.txt", "r", stdin);
      // for writing output to output.txt
      freopen("output.txt", "w", stdout);
  #endif

    int t;
    cin>>t;
    
    while(t--){
        int x; cin >> x;

        int temp = x, count = 0;
        while(temp > 0){
            count++;
            temp /= 10;
        }
        if(count == 2) count = 3;
        else if(count == 3) count = 6;
        else if(count == 4) count = 10;
        cout << ((x%10)-1)*10 + count << endl;

                
        
    }
    return 0;
}






















 