#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj, capacity, ans, org_cap;

int bfs(int s, int t, vector<int>& par) {
    fill(par.begin(), par.end(), -1);
    par[s] = -2;
    queue<pair<int,int>> q;
    q.push({s,1e9});
    while (!q.empty()) {
        auto [cur, flow] = q.front(); q.pop();
        if (cur == t) return flow;
        for (auto next : adj[cur]) {
            if (par[next] == -1 && capacity[cur][next] > 0) {
                par[next] = cur;
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
        int cur = t;
        flow += new_flow;
        while (cur != s) {
            int prev = par[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
}

void extract(int s, int t, int num_paths) {
    vector<vector<int>> flow(n+1, vector<int>(n+1));

    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) {
            if (org_cap[u][v] > 0) {
                flow[u][v] = org_cap[u][v] - capacity[u][v];
            }
        }
    }

    for (int i = 0; i < num_paths; i++) {
        vector<int> path;
        int cur = s;
        path.push_back(cur);
        while (cur != t) {
            for (int next : adj[cur]) {
                if (flow[cur][next] > 0) {
                    flow[cur][next]--;
                    path.push_back(next);
                    cur = next; 
                    break;
                }
            }
        }
        ans.push_back(path);
    }
}

void solve() {
    cin >> n >> m;
    adj.resize(n+1);
    capacity.resize(n+1,vector<int>(n+1));
    org_cap.resize(n+1,vector<int>(n+1));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        capacity[u][v] += 1;
        org_cap[u][v] += 1;
    }

    int max_days =  maxFlow(1,n);
    extract(1,n,max_days);
    cout << max_days << '\n';
    for (auto vec : ans) {
        cout << vec.size() << "\n";
        for (auto v : vec) cout << v << " ";
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}