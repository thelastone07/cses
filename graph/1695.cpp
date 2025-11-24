#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adj;
vector<vector<int>> capacity;

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(),-1);
    parent[s] = -2;

    queue<pair<int,int>> q;
    q.push({s,1e9});

    while (!q.empty()) {
        auto [cur, flow] = q.front();
        q.pop();

        if (cur == t) return flow;

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next] > 0) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t) return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}

int maxFlow(int s, int t) {
    int flow = 0;
    vector<int> par(n+1);
    int new_flow;
    while ((new_flow = bfs(s,t,par)) > 0) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = par[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
}

vector<pair<int,int>> findMinCut(int s, int t) {
    vector<bool> reachable(n+1,false);
    queue<int> q;
    q.push(s);
    reachable[s] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : adj[cur]) {
            if (!reachable[next] && capacity[cur][next] > 0) {
                reachable[next] = true;
                q.push(next);
            }
        }
    }

    vector<pair<int,int>> cut_edges;
    for (int u = 1; u <= n; u++) {
        if (reachable[u]) {
            for (int v : adj[u]) {
                if (!reachable[v] && capacity[u][v] == 0) {
                    cut_edges.push_back({u,v});
                }
            }
        }
    }
    return cut_edges;
}

void solve() {
    cin >> n >> m;
    adj.resize(n+1);
    capacity.resize(n+1, vector<int>(n+1));
    for (int i = 0; i < m; i++) {
        int u,v ;
        cin >> u >> v;
        capacity[u][v] += 1;
        capacity[v][u] += 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int min_cut = maxFlow(1,n);
    vector<pair<int,int>> cute_edges = findMinCut(1,n);

    cout << min_cut << '\n';
    for (auto [u,v] : cute_edges) {
        cout << u << " " << v << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}