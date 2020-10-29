

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

bool Power2(int n){
    if(n == 0) return false;

    return (ceil(log2(n)) == floor(log2(n)));
}
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
        int n;
        cin >> n;
        if(n == 1){
            cout << 1 << endl;
            continue;
        }
        if(Power2(n)) cout << -1 << endl;
        else{
            int arr[n+1];
            rep1(i,n){
                arr[i] = i;
                arr[1] = 2, arr[2] = 3, arr[3] = 1;
            }
            for(int i=4;i<=n; i++){
                if(Power2(i)){
                    swap(arr[i], arr[i+1]);
                    i++;
                }
            }
            rep1(i,n) cout << arr[i] << " ";
            cout << endl;
        }

    }
    
    return 0;
} 