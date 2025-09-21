#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<int> inedges(n+1);
    for (int i = 0; i < m ; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        inedges[v]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) if (!inedges[i]) q.push(i);
    vector<int> order;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (auto v : adj[u]) {
            inedges[v]--;
            if (!inedges[v]) q.push(v);
        }
    }
    vector<int> dist(n+1, -1e9), parent(n+1, -1);
    dist[1] = 1; 
    for (int u : order) {
        if (dist[u] < 0) continue;
        for (int v : adj[u]) {
            if (dist[v] < dist[u] + 1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
            }
        }
    }
    if (dist[n] < 0) {
        cout << "IMPOSSIBLE";
        return;
    }

    vector<int> path;
    for (int v = n; v!= -1; v= parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    cout << dist[n] << "\n";
    for (int x : path) cout << x << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}