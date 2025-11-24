#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> vis;
vector<pair<int,int>> dir = {{1,2}, {2,1},
    {-1,2}, {-2,1},
    {-1,-2}, {-2,-1},
    {1,-2}, {2,-1}};

bool valid(int x, int y) {
    return (x >= 1 && x <= 8 && y >= 1 && y <= 8);
}

int howmany(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < dir.size(); i++) {
        auto [dx, dy] = dir[i];
        int newx = dx + x;
        int newy = dy + y;
        if (!valid(newx,newy)) continue;
        if (vis[newx][newy] == 0) cnt++;
    }
    return cnt;
}

bool backtrack(int x, int y, int cnt) {
    if (cnt == 65) return true;
    vector<pair<int,pair<int,int>>> moves;
    for (int i = 0; i < dir.size(); i++) {
        auto [dx, dy] = dir[i];
        int newx = dx + x;
        int newy = dy + y;
        if (!valid(newx,newy)) continue;
        if (vis[newx][newy] == 0) {
            int access = howmany(newx,newy);
            moves.push_back({access,{newx,newy}});
        }
    }
    sort (moves.begin(), moves.end());
    for (auto &[acc, pos] : moves) {
        int newx = pos.first;
        int newy = pos.second;

        vis[newx][newy] = cnt;
        if (backtrack(newx,newy, cnt+1)) return true;
        vis[newx][newy] = 0;
    }
    return false;
}


void solve() {
    int x, y;
    cin >> x >> y;
    swap(x,y);
    int cnt = 1;
    vis.resize(9, vector<int>(9,0));
    vis[x][y] = cnt;
    backtrack(x,y,2);
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            cout << vis[i][j] << " ";
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