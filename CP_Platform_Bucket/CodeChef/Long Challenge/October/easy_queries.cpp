#include<bits/stdc++.h>
using namespace std;

int main(){
	int t, i, T;
	cin >> T;
	for(t = 0; t < T; t++){
		int n, k, e, flag = 1;
		cin >> n >> k;
		long long sum = 0, pending = 0;
		for(i = 0; i < n; i++){
			cin >> e;
			sum += e;
			if (e > k)
				pending += (e-k);
			if (e < k){
				if(e+pending<k){
					flag = 0;
					cout << i+1 <<endl;
				}
			}
		}
		if(flag){
			long long ans = sum/k;
			cout << ans + 1 <<endl; 
		}
	}
}
