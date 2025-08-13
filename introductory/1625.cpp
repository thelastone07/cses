#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    vector<vector<int>> vis(7,vector<int>(7,0));
    vector<pair<int,int>> dir = {{0,-1},{0,1},{1,0},{-1,0}};
    unordered_map<char,int> mp = {{'L',0},{'R',1},{'D',2},{'U',3}};
    int cnt = 0;

    auto valid = [](int i, int j) {
            bool cond = (i >= 0 && i <=6) && (j >= 0 && j <= 6);
            return cond;
        };

    function<void(int,int,int)> dfs = [&](int x, int y, int step) {
        if (x == 6 && y == 0){
            if (step == 48)
            cnt++;
            return;
        }
        if (step >= 48) return;

        
        if ((x == 0 || vis[x-1][y]) && (x == 6 || vis[x+1][y]) && y > 0 && y < 6 && !vis[x][y-1] && !vis[x][y+1]) return;
        if ((y == 0 || vis[x][y-1]) && (y == 6 || vis[x][y+1]) && x > 0 && x < 6 && !vis[x-1][y] && !vis[x+1][y]) return;


        char c = s[step];
        for (int d=0; d < 4; d++) {
            if (c != '?' && d != mp[c]) continue;
            int i = x + dir[d].first;
            int j = y + dir[d].second;

            if (!valid(i,j)) continue;
            if (vis[i][j]) continue;

            vis[i][j] = 1;
            dfs(i,j,step+1);
            vis[i][j] = 0;
        }
    };
    vis[0][0] = 1;
    dfs(0,0,0);
    cout << cnt << '\n';
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}