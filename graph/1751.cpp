#include<bits/stdc++.h>
using namespace std;
int n, sz;
const int INF = 1e9;
vector<int> t;
vector<int> vis;
vector<int> depth, ans;
vector<vector<int>> radj;
vector<int> dfs(int u) {
    int v = t[u];
    while (v != u) {
        v = t[t[v]];
        u = t[u];
    }
    vector<int> cycle;
    v = t[u];
    cycle.push_back(u);
    while (v != u) {cycle.push_back(v);v = t[v];}
    return cycle;
}
void travel(int u, int d) {
    vis[u] = 1;
    depth[u] = d;
    ans[u] = d + sz;
    for (auto v : radj[u]) {
        if (vis[v]) continue;
        if (depth[v] == 0) travel(v,0);
        else travel(v,d+1);
    }
}
void solve() {
    cin >> n;
    t.resize(n+1); vis.resize(n+1); depth.resize(n+1,-INF); radj.resize(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        radj[t[i]].push_back(i);
    }
    ans.resize(n+1);
    for (int i = 1;i  <= n; i++) {
        if (!vis[i]) {
            auto cycle = dfs(i);
            sz = cycle.size();
            for (int j = 0; j < sz; j++) {
                depth[cycle[j]] = 0;
                ans[cycle[j]] = sz;
            }
            travel(cycle[0],0);
        }
    }
    for (int i = 1; i <= n; i++)
    cout << ans[i] << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}