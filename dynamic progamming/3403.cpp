#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n),b(m);
    for (auto &aa : a) cin >> aa;
    for (auto &bb : b) cin >> bb;
    
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max({
                dp[i-1][j-1] + (a[i-1]==b[j-1]),
                dp[i-1][j],
                dp[i][j-1]
            });
        }
    }
    int ans =  dp[n][m];
    cout << ans << "\n";
    vector<int> lcs;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (a[i-1] == b[j-1]) {lcs.push_back(a[i-1]);i--;j--;}
        else if (dp[i-1][j] >= dp[i][j]) i--;
        else  j--;
    }
    reverse(lcs.begin(),lcs.end());
    for (auto x  : lcs) cout << x << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}