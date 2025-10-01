#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
vector<int> t;
vector<vector<int>> succ;
vector<int> vis, depth;

void fill() {
    for(int i = 1; i <k;i++) {
        for (int j = 1; j <= n; j++) {
            succ[i][j] = succ[i-1][succ[i-1][j]];
        }
    }
}

void dfs(int u) {
    vis[u] = true;
    if (!vis[t[u]]) dfs(t[u]);
    depth[u] = depth[t[u]]+1;
}
int jump (int u, int k) {
    if (k < 0) return u;
    ans += k;
    for (int l = k-1; k >= 0; --l) {
        if (k >> l & 1) u = succ[l][u];
    }
    return u;
}


void solve() {
    int q;
    cin >> n >> q;
    t.resize(n+1);
    k = log2(n)+1;
    depth.resize(n+1);
    succ.resize(k,vector<int>(n+1));
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        succ[0][i] = t[i];
    }
    fill();
    for (int i =1; i<= n;i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        ans = 0;
        u = jump(u,depth[u]-depth[v]);
        if (u == v) {
            cout << ans << '\n';
            continue;
        }
        u = jump(u,depth[u]);
        u = jump(u,depth[u]-depth[v]);
        cout << (u==v? ans : -1) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}