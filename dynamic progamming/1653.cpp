#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> w(n);
    for (auto &ww : w) cin >> ww;
    
    vector<pair<int,int>> dp(1 << n,{INT_MAX,0});
    dp[0] = {1,0};
    for (int i = 0; i < (1 << n); i++) {
        auto [rides, last_w] = dp[i];
        for (int j = 0; j < n; j++)
        if (!((1 << j) & i)) {
            int next = i | (1 << j);
            pair<int,int> option;
            if (last_w + w[j] <= x)
            option = {rides, last_w + w[j]};
            else option = {rides+1,w[j]};

            if (option.first < dp[next].first ||
            (option.first == dp[next].first && option.second < dp[next].second))
            dp[next] = option; 
        }
    }
    // for (int i = 0; i < (1 << n); i++) cout << dp[i].first << " ";
    cout << dp[(1<<n) - 1].first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}