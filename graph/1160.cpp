#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> t, vis, depth, ans;
vector<vector<int>> radj;
const int INF = 1e9;
vector<vector<pair<int,int>>> queries;
int hare(int x) {
    int tx = t[x];
    while (x != tx) {
        x = t[x];
        tx = t[t[tx]];
    }
    return x;
}

void mark_depth_cycle(int u, int d, int st) {
    if (u == st) return;
    depth[u] = d;
    mark_depth_cycle(t[u],d-1,st);
}

void dfs(int u, int d) {
    vis[u] = 1;
    int prev_depth = depth[u];
    depth[u] = d;
    for (auto [v, idx] : queries[u]) {
        if (depth[v] > -INF) {
            ans[idx] = depth[u] - depth[v];
        }
        else {
            ans[idx] = -1;
        }
    }
    for (auto v : radj[u]) {
        if (!vis[v]) dfs(v,d+1);
    }
    // depth[u] = prev_depth;
}

void make_neg(int u, int st) {
    while (u != st) {
        depth[u] = -INF;
        u = t[u];
    }
}

void solve() {
    int q;
    cin >> n >> q;
    t.resize(n+1);
    vis.resize(n+1);
    depth.resize(n+1,-INF);
    radj.resize(n+1);
    queries.resize(n+1);
    ans.resize(q);
    for (int i = 1; i <=n; i++) {
        cin >> t[i];
        radj[t[i]].push_back(i);
    }

    for (int i = 0;i < q; i++) {
        int u, v;
        cin >> u >> v;
        queries[u].emplace_back(v,i);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            int cycle_node = hare(i);
            mark_depth_cycle(t[cycle_node],-1,cycle_node);
            dfs(cycle_node,0);
            depth[cycle_node] = -INF;
            make_neg(t[cycle_node],cycle_node);
        }
    }

    for (int i = 0; i < q; i++) 
    cout << ans[i] <<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}