#include<bits/stdc++.h>
using namespace std;

vector<int> par, sz;
int mx_sz = 1;
int find(int x) {
    if (par[x] == x) return x;
    else return par[x] = find(par[x]);
}

void unite(int x, int y) {
    int  px = par[x];
    int py = par[y];
    if (sz[px] > sz[py]) {
        par[py] = px;
        sz[px] += sz[py];
    } else {
        par[px] = py;
        sz[py] += sz[px];
    }
    mx_sz = max({mx_sz,sz[px],sz[py]});
}

void solve() {
    int n, m; cin >> n >> m;
    sz.resize(n+1,1);
    par.resize(n+1);
    int comp = n;
    for (int i = 1; i <= n; i++) par[i] = i;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (find(u) == find(v)) {
            cout << comp << " " << mx_sz << '\n';
        }
        else {
            unite(u,v);
            comp -= 1;
            cout << comp << " " << mx_sz << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}