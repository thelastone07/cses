#include<bits/stdc++.h>
using namespace std;

long long int INF = 1e18;
int n, m;
vector<vector<long long>> capacity;
vector<vector<int>> adj;

long long bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;

    queue<pair<int,long long>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        long long flow = q.front().second;
        q.pop();

        if (cur == t) {
            return flow;
        }

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next] > 0) {
                parent[next] = cur;
                long long new_flow = min(flow, capacity[cur][next]);
                if (next == t) return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}

long long maxFlow(int s, int t) {
    long long flow = 0;
    vector<int> parent(n+1);
    long long new_flow;
    while ((new_flow = bfs(s,t,parent)) > 0) {
        flow += new_flow;
        int cur = t;
        while (cur != s) { 
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
}

void solve() {
    cin >> n >> m;
    capacity.resize(n+1, vector<long long>(n+1));
    adj.resize(n+1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        capacity[u][v] += w;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << maxFlow(1,n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}