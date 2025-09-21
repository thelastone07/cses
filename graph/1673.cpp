#include<bits/stdc++.h>
#include<bitset>
using namespace std;


const int N = 2501;

struct edge {
    int u, v, w;
};

bitset<N> bfs(int s, vector<vector<int>> &g) {
    bitset<N> vis;
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto u : g[x]) {
            if (vis[u]) continue;
            vis[u] = true;
            q.push(u);
        }
    }
    return vis;
}
const long long int INF = 1e18;
void solve() {
    int n, m; cin >> n >> m;
    vector<edge> edges(m);
    vector<vector<int>> adj(n+1), r_adj(n+1);
    for (int i = 0;i <  m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].w = -edges[i].w;
        adj[edges[i].u].push_back(edges[i].v);
        r_adj[edges[i].v].push_back(edges[i].u);
    }
    auto included = bfs(1,adj) & bfs(n,r_adj);
    vector<long long int> dist(n+1,INF);
    dist[1] = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m; j++) {
            auto [u,v,w] = edges[j];
            if (!included[u] || !included[v]) continue;
            if ( dist[u] != INF && dist[v] > dist[u] + w)
            dist[v] = dist[u] + w; 
        }
    }
    bool cycle = false;
    for (int j = 0; j < m; j++) {
        auto [u,v,w] = edges[j];
        if (!included[v] || !included[u]) continue;
        if (dist[u] != INF && dist[v] > dist[u] + w){
            cycle = true;
            break;
        } 
    }
    cout << (cycle ? -1 : -dist[n]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}