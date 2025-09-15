#include<bits/stdc++.h>
using namespace std;
const long long int INF = 1e18;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long int>> dist(n, vector<long long int>(n,INF));
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--;v--;
        dist[u][v] = min(dist[u][v],(long long)c);
        dist[v][u] = min(dist[u][v],(long long)c);
    }
    for (int i = 0; i < n; i++)dist[i][i] = 0;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (dist[i][k]==INF) continue;
            for (int j = 0; j < n; j++) {
                if (dist[j][k]==INF)continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    while (q--) {
        int u, v;
        cin >> u >> v;
        u--;v--;
        cout << (dist[u][v] == INF ? -1 : dist[u][v]) << '\n';
    }

}   

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}