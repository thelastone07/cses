#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<tuple<int,int,int>> v;
vector<int> root, sz;
int find(int x) {
    if (root[x] == x) return x;
    else return root[x] = find(root[x]);
}
void unite(int x, int y) {
    int parx = find(x);
    int pary = find(y);
    if (sz[parx] < sz[pary]) {
        root[parx] = pary;
        sz[pary] += sz[parx];
    }
    else {
        root[pary] = parx;
        sz[parx] += sz[pary];
    }
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.emplace_back(c,a,b);
    }
    sort(v.begin(), v.end());
    root.resize(n+1); sz.resize(n+1,1);
    long long int ans = 0;
    for(int i = 1; i <= n; i++) root[i] = i;
    for (int i = 0; i < m; i++) {
        auto [w, x, y] = v[i];
        if (find(x) == find(y)) continue;
        ans += w;
        unite(x,y);
    }
    if (sz[find(1)] != n) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}