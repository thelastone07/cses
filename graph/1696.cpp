#include<bits/stdc++.h>
using namespace std;

int n, m, k;
vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int,int>> q;
    q.push({s,1e9});

    while (!q.empty()) {
        auto [cur, flow] = q.front(); q.pop();

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

int maxFlow(int s, int t, int total_nodes) {
    int flow = 0;
    vector<int> parent(total_nodes);
    int new_flow;
    while ((new_flow = bfs(s, t, parent)) > 0) {
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
    cin >> n >> m >> k;
    int source = 0;
    int sink = n + m + 1;
    int total_nodes = n + m + 2;

    capacity.assign(total_nodes, vector<int>(total_nodes,0));
    adj.resize(total_nodes);

    for (int i = 1; i <= n; i++) {
        capacity[source][i] = 1;
        adj[source].push_back(i);
        adj[i].push_back(source);
    }

    for (int i = 1; i <= m; i++) {
        int girl_node = n + i;
        capacity[girl_node][sink] = 1;
        adj[girl_node].push_back(sink);
        adj[sink].push_back(girl_node);
    }

    for (int i= 0; i < k; i++) {
        int boy, girl;
        cin >> boy >> girl;
        int girl_node = girl + n;
        capacity[boy][girl_node] = 1;
        adj[boy].push_back(girl_node);
        adj[girl_node].push_back(boy);
    }

    int max_pairs = maxFlow(source, sink, total_nodes);

    vector<pair<int,int>> pairs;
    for (int boy = 1; boy <= n; boy++) {
        for (int girl = 1; girl <= m; girl++) {
            int girl_node = n + girl;
            if (capacity[boy][girl_node] == 0 && capacity[girl_node][boy] == 1)
            pairs.push_back({boy,girl});
        }
    }

    cout << max_pairs << '\n';
    for (auto [boy, girl] : pairs) {
        cout << boy <<  " " << girl << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}