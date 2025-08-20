#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (auto &c : coins) cin >> c;
    vector<long long> dp(x+1);
    dp[0] = 1;
    for (int j = 0; j < n; j++) {
        for (int i = coins[j]; i <= x; i++)
        dp[i] = (dp[i-coins[j]] + dp[i]) % mod;
    }
    cout << dp[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}