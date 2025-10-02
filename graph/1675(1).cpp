#include<bits/stdc++.h>
using namespace std;

template <typename T>
using pq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n+1);
    for (int i = 0;i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int> inMst(n+1,0);
    pq<pair<int,int>> q;
    q.push({0,1});
    long long int ans = 0;
    while (!q.empty()) {
        auto [w, u] = q.top();
        q.pop();
        if (inMst[u]) continue;
        ans += w;
        inMst[u] = 1;
        for (auto [v,ww] : adj[u]) {
            if (inMst[v]) continue;
            q.push({ww,v});
        }
    }
    if (accumulate(inMst.begin(),inMst.end(),0) != n)
    {cout << "IMPOSSIBLE\n"; return;}
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}