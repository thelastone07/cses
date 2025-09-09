#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (auto &ss : s) cin >> ss;
    pair<int,int> a, b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j]=='A')a = {i,j};
            if (s[i][j]=='B')b = {i,j};
        }
    }

    vector<vector<char>> dir(n,vector<char>(m,'0'));
    vector<vector<pair<int,int>>> prev(n, vector<pair<int,int>>(m));
    vector<vector<int>> vis(n, vector<int>(m,0));

    tuple<int,int,char> v[4] = {
        {0,1,'R'}, {0,-1,'L'}, {1,0,'D'}, {-1,0,'U'}
    };

    queue<pair<int,int>> q;
    q.push(a);
    vis[a.first][a.second] = 1;

    auto valid = [&](int x, int y) {
        return (x >= 0 && x < n) && (y >= 0 && y < m) && (s[x][y] != '#');
    };

    while(!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        for (auto [dx,dy,d] : v) {
            int x = i + dx;
            int y = j + dy;
            if (!valid(x,y)) continue;
            if (vis[x][y]) continue;
            vis[x][y] = 1;
            prev[x][y] = {i,j};
            dir[x][y] = d;
            q.push({x,y});
        }
    }

    if (!vis[b.first][b.second]) {
        cout << "NO\n";
        return;
    }

    string ans = "";
    pair<int,int> node = b;
    while (node != a) {
        ans += dir[node.first][node.second];
        node = prev[node.first][node.second];
    }
    reverse(ans.begin(), ans.end());
    cout << "YES\n";
    cout << ans.size() << "\n";
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}