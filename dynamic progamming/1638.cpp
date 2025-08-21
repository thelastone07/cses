#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
void print(vector<vector<long long>> &x) {
    for (auto v : x) {
        for (auto ele : v) cout << ele << " ";
        cout << '\n';
    }
    cout << '\n';
}
void solve() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) 
    cin >> grid[i];

    vector<vector<long long>> dp(n,vector<long long>(n,0));
    vector<vector<int>> vis(n,vector<int>(n,0));
    dp[0][0] = 1;
    if (grid[0][0] == '*') {
        cout << 0;
        return;
    }

    queue<pair<int,int>> q;
    q.push({0,0});
    while (!q.empty()) {
        auto [x,y] = q.front();
        q.pop();
        if (grid[x][y]=='*' || vis[x][y] ) continue;
        vis[x][y] = 1;
        if (x - 1 >= 0) dp[x][y] += dp[x-1][y];
        if (y - 1 >= 0) dp[x][y] += dp[x][y-1];
        dp[x][y] %= mod;

        if (x+1 < n && grid[x+1][y] != '*') q.push({x+1,y});
        if (y+1 < n && grid[x][y+1] != '*') q.push({x,y+1}); 
        

    }
    // print(dp);

    cout << dp[n-1][n-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}