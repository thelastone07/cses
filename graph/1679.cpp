#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<int> inedges(n+1);
    for (int i = 0;i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        inedges[v]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) if (!inedges[i]) q.push(i);
    vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (auto v : adj[u]) {
            inedges[v]--;
            if (!inedges[v]) q.push(v);
        }
    }
    if (order.size() != n) {
        cout << "IMPOSSIBLE";
        return;
    }
    for (auto o : order) cout << o << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}