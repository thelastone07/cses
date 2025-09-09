#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> par(n+1);
    vector<int> vis(n+1);

    queue<int> q;
    q.push(1);
    vis[1] = 1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : adj[v]) {
            if (vis[u]) continue;
            vis[u] = 1;
            par[u] = v;
            q.push(u);
        }
    }

    if (!vis[n]) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    vector<int> ans;
    int node = n;
    while (node != 1) {
        ans.push_back(node);
        node = par[node];
    }
    cout << ans.size() + 1 << '\n' << 1 << " ";
    reverse(ans.begin(), ans.end());
    for (auto a : ans) cout << a << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}