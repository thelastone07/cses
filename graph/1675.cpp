#include<bits/stdc++.h>
using namespace std;
template <class T>
using q = priority_queue<T, vector<T>, greater<T>>;
void solve() {
    int n, m;
    cin >> n >> m;
    q<tuple<int,int,int>> pq;
    vector<int> vis(n+1);
    for (int i = 1; i <= m; i++) {
        int a, b, c; cin >> a >> b >> c;
        pq.push({c,min(a,b),max(a,b)});
    }
    int ans = 0;
    while (!pq.empty()) {
        auto [c,a,b] = pq.top();
        pq.pop();
        if (vis[a] && vis[b]) continue;
        ans += c;
        vis[a] = 1; vis[b] = 1;
    }
    cout << ans ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}