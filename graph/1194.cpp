#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<string> s(n);
    for (auto &ss : s) cin >> ss;
    vector<pair<int,int>> monsters, goals;
    pair<int,int> a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'M') monsters.push_back({i,j});
            if (s[i][j] == 'A') a = {i,j};
            if (i == 0 || i == n-1 || j == 0 || j == m-1) {
                if (s[i][j] == 'A') {
                    // cout << i << " " << j << '\n';
                    cout << "YES\n";
                    cout << 0;
                    return;
                }
                if (s[i][j] == '.')
                goals.push_back({i,j});
            }
            
            
        }
    }

    tuple<int,int,char> v[4] = {
        {0,1,'R'}, {0,-1,'L'}, {1,0,'D'}, {-1,0,'U'}
    };

    vector<vector<int>> mtime(n,vector<int>(m,-1));
    queue<pair<int,int>> q;
    for (auto monster : monsters) {
        q.push(monster);
        mtime[monster.first][monster.second] = 0;
    }

    auto valid = [&](int x, int y) {
        return (x >= 0 && x < n) && (y >= 0 && y < m) && (s[x][y] != '#');
    };

    while (!q.empty()) {
        auto [i,j] = q.front();
        q.pop();
        int t = mtime[i][j];
        for (auto [dx, dy, _] :v ) {
            int x = i + dx;
            int y = j + dy;
            if (!valid(x,y)) continue;
            if (mtime[x][y] != -1) continue;
            mtime[x][y] = t + 1;
            q.push({x,y});
        }
    }

    vector<vector<int>> mytime(n, vector<int>(m,-1));
    vector<vector<char>> dir(n,vector<char>(m));
    vector<vector<pair<int,int>>> prev(n,vector<pair<int,int>>(m));
    q.push(a);
    mytime[a.first][a.second] = 0;
    while (!q.empty()) {
        auto [i,j] = q.front();
        q.pop();
        int t = mytime[i][j];
        for (auto [dx,dy,d]:v) {
            int x = i + dx;
            int y = j + dy;
            if (!valid(x,y)) continue;
            int mon_time = mtime[x][y] != -1 ? mtime[x][y] : 1e9;
            if (mytime[x][y] != -1) continue;
            if (mon_time <= t+1) continue;
            mytime[x][y] = t+1;
            dir[x][y] = d;
            prev[x][y] = {i,j};
            q.push({x,y});
        }
    }
    pair<int,int> b = {-1,-1};
    for (int i = 0; i < goals.size(); i++) {
        if (mytime[goals[i].first][goals[i].second] != -1) {
            b = goals[i];
            break;
        }
    }
    if (b.first == -1) {
        cout <<"NO\n";
        return;
    }
    cout << "YES\n";
    string ans = "";
    pair<int,int> node = b;
    // cout << b.first << " " << b.second << '\n';
    while (node != a) {
        ans.push_back(dir[node.first][node.second]);
        node = prev[node.first][node.second];
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}