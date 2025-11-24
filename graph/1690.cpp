#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adj;
vector<vector<int>> dp;  
int mod = 1e9+7;
 
void solve() {
    cin >> n >> m;
    adj.resize(n+1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    dp.resize(1 << n, vector<int>(n+1, 0));
    dp[1 << (1-1)][1] = 1; 
    
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int u = 1; u <= n; u++) {
            if (!(mask & (1 << (u-1)))) continue; 
            if (dp[mask][u] == 0) continue;
            
            for (auto v : adj[u]) {
                if (mask & (1 << (v-1))) continue; 
                
                int newMask = mask | (1 << (v-1));
                dp[newMask][v] = (dp[newMask][v] + dp[mask][u]) % mod;
            }
        }
    }
    
    cout << dp[(1 << n) - 1][n]; 
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}