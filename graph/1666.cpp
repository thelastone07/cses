#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> vis;

void dfs(int v) {
    vis[v] = 1;
    for (auto u : adj[v]) {
        if (!vis[u]) dfs(u);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    adj.resize(n+1); vis.resize(n+1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            ans.push_back(i);
        }
    }
    cout << ans.size() -1 << '\n';
    for (int i = 0; i < ans.size()-1; i++) {
        cout << ans[i] << " " << ans[i+1];
        cout << '\n';
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}