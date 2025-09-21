#include<bits/stdc++.h>
using namespace std;
template <typename T>
using revPQ = priority_queue<T, vector<T>, greater<T>>;
vector<vector<pair<int,int>>> adj, radj;
vector<long long int> price, n_min_price, min_flights, max_flights;
int n, m; 
const long long int INF = 1e18;
const int mod = 1e9 + 7;
vector<int> ready;

void f(int x) {
    if (ready[x]) return;
    ready[x] = 1;
    if (x == n) {
        n_min_price[n] = 1;
        min_flights[n] = 0;
        max_flights[n] = 0;
        return;
    }
    for (auto [y,w] : adj[x]) {
        if (price[x] == price[y] + w) {
            f(y);
            n_min_price[x] = (n_min_price[x] + n_min_price[y]) % mod;
            min_flights[x] = min(min_flights[x], min_flights[y] + 1);
            max_flights[x] = max(max_flights[x],max_flights[y]+1);
        }
    }
}

void solve() {
    cin >> n >> m;
    adj.resize(n+1);
    radj.resize(n+1);
    price.resize(n+1,INF);
    n_min_price.resize(n+1,0);
    min_flights.resize(n+1,INF);
    max_flights.resize(n+1,-INF);
    ready.resize(n+1,0);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].emplace_back(v,w);
        radj[v].emplace_back(u,w);
    }
    revPQ<pair<long long int,int>> q;
    price[n]=0;
    q.push({0,n});
    while (!q.empty()) {
        auto [d,u] = q.top();q.pop();
        if (d > price[u]) continue;
        for (auto [v,w] : radj[u]) {
            if (w + d < price[v]) {
                price[v] = w + d;
                q.push({w+d,v});
            }
        }
    }
    f(1);
    cout << price[1] << " " << n_min_price[1] << " " << min_flights[1] << " " << max_flights[1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}