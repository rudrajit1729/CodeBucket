#include <iostream>
using namespace std;

// You can find the problem statement at https://codeforces.com/contest/1430/problem/C

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cout << 2 << endl;
        cout << n <<" "<< n-1 << endl;
        for (int j = n; j >= 3; j--) {
            cout << j <<" "<< j-2 << endl;
        }
    }
}