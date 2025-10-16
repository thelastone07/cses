#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj, radj;
vector<bool> visited;
vector<int> order, comp, rorder;

void dfs1(int v) {
    visited[v] = true;
    for (auto u : adj[v]) if (!visited[u]) dfs1(u);
    order.push_back(v);
}

void dfs2(int v, int c) {
    comp[v] = c;
    for (auto u : radj[v]) if (comp[u] == -1) dfs2(u,c);
    rorder.push_back(v);
}

void solve() {
    int n, m;
    cin >> n >> m;
    adj.resize(2*m);
    radj.resize(2*m);
    visited.resize(2*m,false);
    order.clear(); comp.resize(2*m,-1); rorder.clear();
    for (int i = 0; i < n; i++) {
        char ch1,ch2;
        int a, b;
        cin >> ch1 >> a >> ch2 >> b;
        a--; b--;
        int node_a = 2*a + (ch1 == '+');
        int node_b = 2*b + (ch2 == '+');
    
        adj[node_a ^ 1].push_back(node_b);
        adj[node_b ^ 1].push_back(node_a);
        radj[node_b].push_back(node_a ^ 1);
        radj[node_a].push_back(node_b ^ 1);
    }
    for (int i = 0; i < 2*m; i++) if (!visited[i]) dfs1(i);
    reverse(order.begin(), order.end());
    int scc_num = 0;
    vector<bool> chosen, assignment;
    assignment.resize(m,false);
    chosen.resize(m,false);
    for (auto o : order) if (comp[o] == -1) dfs2(o,scc_num++);
    for (int i = 0; i < m; i++) {
        if (comp[i] == comp[i^m]) {
            cout << "IMPOSSIBLE";
            return;
        }
    }
    reverse(rorder.begin(), rorder.end());
    for (auto node : rorder) {
        int what = node / 2;
        if (chosen[what]) continue;
        chosen[what] = 1;
        assignment[what] = node & 1;
    }
    for (int i = 0; i < m; i++) {
        if (assignment[i]) cout <<"+ ";
        else cout << "- "; 
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}