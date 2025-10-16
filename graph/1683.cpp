#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> adj,radj;
vector<int> vis;
stack<int> st;

void dfs1(int u) {
    vis[u] = 1;
    for (int v : adj[u]) if (!vis[v]) dfs1(v);
    st.push(u);
}

void dfs2(int u, vector<int>& component) {
    vis[u] = 1;
    component.push_back(u);
    for (int v : radj[u]) {
        if (!vis[v]) dfs2(v,component);
    }
}

void solve() {
    cin >> n >> m;
    adj.resize(n+1); radj.resize(n+1);
    for (int i = 0; i < m; i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    vis.resize(n+1);
    for (int i = 1; i <= n; i++)
    if (!vis[i]) dfs1(i);

    vis.assign(n+1,0);
    vector<vector<int>> sccs;
    while (!st.empty()){
        int u = st.top(); st.pop();
        if (!vis[u]) {
            vector<int> component;
            dfs2(u,component);
            sccs.push_back(component);
        }
    }
    vector<int> ans(n+1);
    for (int i = 0; i <sccs.size(); i++) {
        for (auto v : sccs[i])
        ans[v] = i+1;
    }
    cout << sccs.size() << "\n";
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}