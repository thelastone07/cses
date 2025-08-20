#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, target;
    cin >> n >> target;
    vector<int> x(n);
    for (auto &xx : x) cin >> xx;
    vector<int> dp(target+1,1e9);
    dp[0] = 0;
    for (int i = 1; i <= target; i++) {
        for (auto xx : x) if (i - xx >= 0 && dp[i-xx] != 1e9)
        dp[i] = min(dp[i],1+dp[i-xx]);
    }
    if (dp[target]==1e9) cout << -1 << '\n';
    else cout << dp[target];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}