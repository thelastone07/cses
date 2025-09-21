#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n+1), radj(n+1);
    vector<int> inedges(n+1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
        inedges[v]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) if (!inedges[i])q.push(i);
    vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (auto v : adj[u]) {
            inedges[v]--;
            if (!inedges[v])q.push(v);
        }
    }
    vector<int> times(n+1,0);
    times[1] = 1;
    for (auto u : order) {
        for (auto v : radj[u]) {
            if (times[v])
            times[u] = (times[u] + times[v]) % mod; 
        }
    }
    cout << times[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}