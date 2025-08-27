#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (auto &xx : x) cin >> xx;
    vector<vector<int>> dp(n,vector<int>(n));
    if (n%2) {
        for (int i = 0; i < n; i++)
        dp[i][i] = x[i];
    }
    else {
        for (int i = 0; i < n-1; i++)
        dp[i][i+1] = max(x[i],x[i+1]);
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}