#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x; 
    vector<int> c(n);
    for (auto &cc : c) cin >> cc;
    vector<long long> dp(x+1);
    dp[0] = 1;
    int mod = 1e9 + 7;
    for (int i = 1; i <= x; i++) {
        for (auto coin : c) if (i - coin >= 0)
        dp[i] += dp[i-coin];
        dp[i] %= mod;
    }
    cout << dp[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}