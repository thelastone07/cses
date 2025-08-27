#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s,t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dist(n+1,vector<int>(m+1));
    for (int i = 0; i <= n;i++) {
        dist[i][0] = i;
    }
    for (int j = 0; j <= m; j++) {
        dist[0][j] = j;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m;j++) {
            dist[i][j] = min({
                dist[i][j-1]+1,
                dist[i-1][j] + 1,
                dist[i-1][j-1] + (s[i-1] != t[j-1])
            });
        }
    }
    cout << dist[n][m] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}