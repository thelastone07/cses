#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e18;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--; v--;
        adj[u].push_back({v, c});
    }

    vector<long long int> dist(n, INF);
    dist[0] = 0;

    priority_queue<pair<long long int,int>, vector<pair<long long int,int>>, greater<pair<long long int,int>>> pq;
    pq.emplace(0, 0);

    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();

        if (w > dist[u]) continue;  

        for (auto [v, c] : adj[u]) {
            long long int d = w + c;
            if (d < dist[v]) {
                dist[v] = d;     
                pq.emplace(d, v);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << dist[i] << " \n"[i == n-1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
