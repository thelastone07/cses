#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> adj, radj;
vector<int> vis, rvis;

void dfs(int u) {
    vis[u] = 1;
    for (auto v :adj[u]) {
        if (vis[v]) continue;
        dfs(v);
    }
}

void rdfs(int u) {
    rvis[u] = 1;
    for (auto v :radj[u]) {
        if (rvis[v]) continue;
        rdfs(v);
    }
}

void solve() {
    int m;
    cin >> n >> m;
    adj.resize(n+1); radj.resize(n+1);
    for (int i = 0;i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    vector<pair<int,int>> ans;
    vis.resize(n+1); rvis.resize(n+1);
    dfs(1);
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            cout << "NO\n";
            cout << 1 << " " << i;
            return;
        }
    } 
    rdfs(1);
    for (int i = 2; i <= n; i++) {
        if (!rvis[i]) {
            cout << "NO\n";
            cout << i << " " << 1;
            return;
        }
    }
   cout << "YES";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}