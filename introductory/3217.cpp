#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
void solve() {
    int n;
    cin >> n; 
    vector<vector<int>> dp(n,vector<int>(n,INF));
    dp[0][0] = 0; 
    auto valid =[&](int x) {
        bool cond = x >= 0 && x < n;
        return cond;
    };

    vector<pair<int,int>> jumps = {{1,2}, {-1,2},{-1,-2},{1,-2},{2,1},{2,-1},{-2,-1},{-2,1}};
    queue<pair<int,int>> q;
    q.push({0,0});
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        for (auto [r, c]: jumps ) {
            if (valid(i+r) && valid(j+c)) {
                if (dp[i+r][j+c] > dp[i][j] + 1){
                    dp[i+r][j+c] = dp[i][j] +1;
                    q.push({i+r,j+c});
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
        cout << dp[i][j] << " ";
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}