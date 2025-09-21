#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int,int>>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }

    vector<vector<long long>> dist(n+1); // store up to k distances per node

    priority_queue<
        pair<long long,int>,
        vector<pair<long long,int>>,
        greater<>
    > pq;

    pq.push({0, 1});
    dist[1].push_back(0);

    vector<long long> answers;

    while (!pq.empty() && (int)answers.size() < k) {
        auto [d, u] = pq.top(); pq.pop();
        if (u == n) {
            answers.push_back(d);
        }
        if ((int)dist[u].size() > k) continue;

        for (auto [v, w] : adj[u]) {
            long long nd = d + w;
            if ((int)dist[v].size() < k) {
                dist[v].push_back(nd);
                pq.push({nd, v});
            }
        }
    }

    for (int i = 0; i < k; i++) {
        cout << answers[i] << " \n"[i==k-1];
    }
}
