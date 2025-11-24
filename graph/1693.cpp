#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> path;
vector<int> in, out;
int n, m;

bool euler(int st, int en) {
    if (out[st]-in[st] != 1 || in[en] - out[en] != 1) return false;
    for (int i = 2; i < en; i++) if (in[i] != out[i]) return false;

    vector<int> stack;
    stack.push_back(st);
    while (stack.size()) {
        int curr = stack.back();
        if (adj[curr].size()) {
            int nxt = adj[curr].back();
            adj[curr].pop_back();
            stack.push_back(nxt);
        } else {
            path.push_back(curr);
            stack.pop_back();
        }
    }
    reverse(path.begin(), path.end());
    if (path[0] == st && path.back() == en && path.size() == m+1) return true;
    return false;
}

void solve() {
    cin >> n >> m;
    adj.resize(n+1);
    in.resize(n+1); out.resize(n+1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        out[u]++; in[v]++;
    }
    bool has_path = euler(1,n);
    if (has_path) {
        for (auto p : path) cout << p << " ";
    }
    else cout << "IMPOSSIBLE";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}