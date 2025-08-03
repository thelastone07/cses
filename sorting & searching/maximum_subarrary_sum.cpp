#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &aa : a) cin >> aa;
    long long int mx = a[0], sum = a[0];
    for (int i = 1; i < n; i++) {
        sum = max((long long int)a[i],sum + a[i]);
        mx = max(mx,sum);
    }
    cout << mx << "\n";
}

signed main() {
    solve();return 0;
}