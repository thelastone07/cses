#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    long long int sum = 0;
    for (int i = 0; i < n-1; i++){
        int x;
        cin >> x;
        sum += x;
    }
    long long int nsum = 1LL* n * (n + 1) / 2;
    cout << nsum - sum << '\n';
}

signed main() {
    solve();
    return 0;
}