#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (auto &vv : v) cin >> vv;
    map<int,int> mp;
    for (int i = 0; i < n; i++) {
        if (mp[x-v[i]]) {
            cout << i + 1 << " " << mp[x - v[i]] << "\n";
            return;
        }
        mp[v[i]] = i + 1;
    }
    cout << "IMPOSSIBLE\n";
}

signed main() {
    solve(); return 0;
}