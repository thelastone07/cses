#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n,vector<int>(m)), h(n,vector<int>(m,4));
    for (int i = 0; i < n; i++) 
    for (int j = 0; j < m; j++) {
        char c; cin >> c;
        g[i][j] = c - 'A';
    }
    queue<pair<int,int>> q;
    q.push({0,0});
    vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};

    auto valid = [&](int x, int y) {
        bool cond = (x >= 0 && x < n) && (y >= 0 && y < m);
        return cond;
    };

    while(!q.empty()) {
        auto [i,j] = q.front();
        q.pop();
        
        if (h[i][j] != 4) continue;
        
        vector<bool> cover(4,false);
        cover[g[i][j]] = true;
        
        for (auto [dx,dy]: dir) {
            int x = dx + i;
            int y = dy + j;
            if (!valid(x,y))continue;
            if (h[x][y] == 4) {
                q.push({x,y});
                continue;
            }
            cover[h[x][y]] = true;
        }
        
        for (int k = 0; k < 4; k++) {
            if (!cover[k]) {h[i][j] = k;break;}
        }
        if (h[i][j] == 4) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << char(h[i][j] + 'A');
        }
        cout << '\n';
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}