#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj, radj, nadj;
vector<int> vis, order, scc, coins;
vector<long long int> dp, vals;
void dfs(int u) {
    vis[u] = 1;
    for (auto v : adj[u]) if (!vis[v]) dfs(v);
    order.push_back(u);
}

long long int dfs2(int u, int num) {
    scc[u] = num;
    long long int val = coins[u];
    for (auto v : radj[u]) {
        if (scc[v] == 0) val += dfs2(v,num);
    }
    return val;
}
long long int dfs3(int u) {
    if (dp[u] != -1) return dp[u];
    long long int val = 0;
    for (auto v : nadj[u]) {
        val = max(val, dfs3(v));
    }
    return dp[u] = val + vals[u];
}

void solve() {
    int n, m; cin >> n >> m;
    coins.resize(n+1);
    adj.resize(n+1); radj.resize(n+1);
    for (int i = 0; i < n; i++) cin >> coins[i+1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    vis.resize(n+1,0);
    for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i);
    reverse(order.begin(), order.end());
    scc.resize(n+1,0);
    vals.resize(n+1,0);
    int scc_count = 0;
    for (int i = 0; i < n; i++) {
        int j = order[i];
        if (!scc[j]) {
            vals[scc_count+1] = dfs2(j,scc_count+1);
            scc_count++;
        }
    }
    nadj.resize(scc_count+1);
    for (int u = 1; u <= n; u++) {
        for (auto v : adj[u]) {
            if (scc[v] != scc[u])
            nadj[scc[u]].push_back(scc[v]);
        }
    }

    for (int i = 1; i <= scc_count; i++) {
        sort(nadj[i].begin(), nadj[i].end());
        nadj[i].erase(unique(nadj[i].begin(),nadj[i].end()), nadj[i].end());
    }
    dp.resize(scc_count+1,-1);
    for (int i =1; i <= scc_count; i++) {
        if (dp[i]==-1) dfs3(i);
    }
    cout << *max_element(dp.begin(), dp.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}