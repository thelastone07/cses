#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    
    vector<long long> dp(n+1);
    dp[0] = 1;
    for (int i = 1;i <= n; i++) {
        dp[i] += dp[i-1];
        if (i - 2 >= 0)
        dp[i] += dp[i-2];
        if (i - 3 >= 0)
        dp[i] += dp[i-3];
        if (i - 4 >= 0) 
        dp[i] += dp[i-4];
        if (i - 5 >= 0)
        dp[i] += dp[i-5];
        if (i - 6 >= 0)
        dp[i] += dp[i-6];
        dp[i] %= mod;
    }
    cout << dp[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}