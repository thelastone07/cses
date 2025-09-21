#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<tuple<int,int,int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    vector<long long> dist(n+1, 0);
    vector<int> par(n+1, -1);
    int node = -1;

    for (int i = 0; i < n; i++) {
        node = -1;
        for (auto [u, v, w] : edges) {
            if (dist[v] > dist[u] + w) {
                dist[v] = max(-INF, dist[u] + w);
                par[v] = u;
                node = v;
            }
        }
    }

    if (node == -1) {
        cout << "NO\n";
        return;
    }

    // Ensure node is inside the cycle
    for (int i = 0; i < n; i++) node = par[node];

    vector<int> cycle;
    int cur = node;
    do {
        cycle.push_back(cur);
        cur = par[cur];
    } while (cur != node);
    cycle.push_back(node);
    reverse(cycle.begin(), cycle.end());

    cout << "YES\n";
    for (int c : cycle) cout << c << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
