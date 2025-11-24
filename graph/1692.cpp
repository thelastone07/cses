#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>> adj;
map<int,string> mp;
map<string, int> num;

vector<int> used, euler;

void dfs (int u) {
    while (!adj[u].empty()) {
        auto [v, idx] = adj[u].back();
        adj[u].pop_back();
        if (used[idx]) continue;
        used[idx] = 1;
        dfs(v);
    }
    euler.push_back(u);
}
void solve() {
    int n; cin >> n;
    if (n == 1) {
        cout << "10";
        return;
    }
    for (int i = 0; i < (1 << (n-1)); i++) {
     mp[i] = bitset<16>(i).to_string().substr(16-(n-1)); 
     num[mp[i]] = i;  
    }
    adj.resize(1 << (n-1));
    for (int i = 0; i < (1 << (n-1)); i++) {
        string s = mp[i];
        string t0 = (s + '0').substr(1);
        string t1 = (s + '1').substr(1);
        adj[i].push_back({num[t0],i*2});
        adj[i].push_back({num[t1],i*2+1});
    }
    used.resize((1 << n));
    int st = 0;
    dfs(0);
    reverse(euler.begin(),euler.end());
    string result = mp[euler[0]];
    for (int i = 0; i < euler.size() - 1; i++) {
        int u = euler[i];
        int v = euler[i + 1]; 
        string s = mp[u];
        string target = mp[v];
        if ((s + '0').substr(1) == target) {
            result += '0';
        } else {
            result += '1';
        }
    }
    cout << result << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}