#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>> adj;
vector<int> used, euler;

void dfs (int u) {
    while (!adj[u].empty()) {
        auto [v, idx] = adj[u].back();
        adj[u].pop_back();
        if (used[idx]) continue;
        used[idx] = 1;
        dfs(v);
    }
    euler.push_back(u);
}
void solve() {
    int n, m;
    cin >> n >> m;
    adj.resize(n+1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
    }
    used.resize(m);
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() % 2 != 0) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    int st = 1;
    dfs(st);
    if (euler.size() != m + 1) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    reverse(euler.begin(), euler.end());
    for (auto v : euler) cout << v << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}