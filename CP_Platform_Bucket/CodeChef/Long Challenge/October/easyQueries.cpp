#include<bits/stdc++.h>
using namespace std;

int main(){
	int t, i, T, e, flag;
	cin >> T;
	for(t = 0; t < T; t++){
		int n, k;
		cin >> n >> k;
		flag = 1;
		long long pending = 0, sum = 0, ans;
		for(i = 0; i < n; i++){
			cin >> e;
			pending += max((e-k), 0);
			sum += e;
			if (e < k){
				if(e + pending < k && flag){
					ans = i;
					flag = 0;
				}
				pending -= (k-e);
				if(pending < 0) pending = 0;
			}
		}
		if(flag)
			ans = sum/k;
		cout << ans+1 << endl;
	}
}


