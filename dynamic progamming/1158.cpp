#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> h(n), s(n);
    for (auto &hh : h) cin >> hh;
    for (auto &hh : s) cin >> hh;
    vector<int> dp(x+1,-1);
    vector<int> subsum(n);
    subsum[0] = h[0];
    for (int i = 1; i < n; i++)
    subsum[i] = subsum[i-1] + h[i];
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = min(x,subsum[i]); j >= h[i];j--) {
            if (dp[j-h[i]] != -1) 
            dp[j] = max(dp[j-h[i]] + s[i],dp[j]);
        }
    }
    cout << *max_element(dp.begin(), dp.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}