#include<bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 1;

int dp[N][102];

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n+1);
    for (int i = 0; i < n; i++) cin >> a[i+1];

    for (int j = 1; j <= m; j++)
    if (a[1] == 0 || a[1] == j)
    dp[1][j] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == 0 || a[i] == j) {
                for (int k = -1; k <= 1; k++) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j+k]) % M;
                }
            }
        }
    }

    int result = 0;
    for (int j = 1; j <=m ;j++) {
        result = (result + dp[n][j]) % M;
    }

    cout << result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}