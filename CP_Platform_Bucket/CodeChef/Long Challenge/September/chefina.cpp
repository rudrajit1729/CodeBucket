#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long int
void solve();
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	clock_t tStart = clock();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
#ifndef ONLINE_JUDGE
	fprintf(stderr, "Runtime: %.10fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
#endif
	return 0;
}


ll position(ll s)
{
	long double a = sqrtl(1ul+4*(s));
	a -= 1.0;
	a /= 2.0;
	ll ans = a;
	return ans;
}

void solve()
{
	ll tests;
	cin >> tests;
	while(tests--)
	{
		ll n;
		cin >> n;
		
		if (n == 0 || n == 1 || n == 2){
			cout << 0 << endl;
			continue;
		}
		ll t = (n*(n+1))/2;
		if(t&1){
			cout << 0 << endl;
			continue;
		}
		ll ind = position(t);
		ll x = (ind * (ind+1)) / 2;
		if(t/2 == x){
			ll ans = (ind * (ind - 1ul)) /2l+((n-ind)*(n-ind-1ul))/2l+(n-ind);
			cout<<ans<<endl;
		}
		else
			cout << n - ind << endl;
	}
}


