#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    } 
    vector<int> vis(n+1), par(n+1);
    int st = -1, en = -1;
    function<bool(int,int)> dfs= [&](int u, int p)->bool {
        vis[u] = 1;
        for (auto v : adj[u]) {
            if (v == p) continue;
            if (vis[v]) {
                st = u;
                en = v;
                return true;
            }
            par[v] = u;
            if (dfs(v,u)) return true;
        }
        return false;
    };
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && dfs(i,-1)) break;
    }
    if (st == -1) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    vector<int> ans;
    ans.push_back(en);
    for (int v = st; v!= en; v = par[v]) {
        ans.push_back(v);
    }
    ans.push_back(en);

    cout << ans.size() << '\n';
    for (auto a : ans) cout << a << " ";
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}