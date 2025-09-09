#include<bits/stdc++.h>
using namespace std;
vector<string> s;
vector<vector<int>> vis;
vector<int> dx = {0,0,-1,1};
vector<int> dy = {1,-1,0,0};
int n, m;

bool valid (int x, int y) {
    return (x >= 0 && x < n) && ( y >= 0 && y < m) && s[x][y] == '.';
}

void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int X = x + dx[i];
        int Y = y + dy[i];
        if (!valid(X,Y)) continue;
        if (vis[X][Y]) continue;
        dfs(X,Y);
    }
}

void solve() {
    cin >> n >> m;
    s.resize(n);
    for (auto &ss : s) cin >> ss;
    int cnt = 0;
    vis.resize(n,vector<int>(m,0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && s[i][j] == '.')
            {
                dfs(i,j);
                cnt++;
            }
        }
    }
    cout << cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}