#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> vis, st, par;
int start = -1, en = -1;

bool dfs(int u) {
    vis[u] = 1;
    st[u] = 1;

    for (auto v : adj[u]) {
        if (!vis[v]) {
            par[v] = u;
            if (dfs(v)) return true;
        }
        else if (st[v]) {
            start = v;
            en = u;
            return true;
        }
    }
    st[u] = 0;
    return false;

}

void solve() {
    int n, m;
    cin >> n >> m;
    adj.resize(n+1);
    vis.resize(n+1);
    st.resize(n+1);
    par.resize(n+1,-1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i] && dfs(i)) break;
    }
    if (start == -1) {
        cout << "IMPOSSIBLE";
        return;
    }
    vector<int> cycle;
    cycle.push_back(start);
    for (int v = en; v != start; v = par[v])  {
        cycle.push_back(v);
    }
    cycle.push_back(start);
    reverse(cycle.begin(),cycle.end());
    cout << cycle.size() << "\n";
    for (auto c : cycle) cout << c << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}