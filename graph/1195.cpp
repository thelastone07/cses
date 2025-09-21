#include<bits/stdc++.h>
using namespace std;
const long long int INF = 1e18;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v,w});
    } 
    vector<vector<long long int>> dist(n,vector<long long int>(2,INF));
    dist[0][0] = 0; dist[0][1] = 0;
    priority_queue<tuple<long long int,int,int>, vector<tuple<long long int,int,int>>,greater<tuple<long long int,int,int>>> pq;
    pq.push({0,0,0});
    while (!pq.empty()) {
        auto [d,u,used] = pq.top();
        pq.pop();
        if (dist[u][used] < d) continue;
        for (auto [v,w] : adj[u]) {
            long long int updated_d = 0;
            if (!used) {
                updated_d = d + w/2;
                if (updated_d < dist[v][1]) {
                    pq.push({updated_d,v,1});
                    dist[v][1] = updated_d;
                }
                updated_d = 0;
            }
            updated_d = w + d;
            if (updated_d < dist[v][used]) {
                pq.push({updated_d,v,used});
                dist[v][used] = updated_d;
            }
        }
    }
    
    cout << min(dist[n-1][0],dist[n-1][1]) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}