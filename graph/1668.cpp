#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> colors(n+1,-1);
    bool imp = false;
    function<void(int,int)> dfs=[&](int u,int c) {
        colors[u] = c;
        for (auto v : adj[u]) {
            if (colors[v] == c) {
                imp = true;
                return;
            }
            if (colors[v] == -1) dfs(v,!c);
        }
    };

    for (int i = 1; i <= n; i++) {
        if (colors[i] == -1) dfs(i,1);
    }
    if (imp) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    for (int i = 1; i <= n; i++) cout << colors[i]+1 << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}