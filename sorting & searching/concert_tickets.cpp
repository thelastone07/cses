#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    multiset<int> h;
    vector<int> t(m);
    for (int i= 0;i < n; i++) {
        int hh; cin >> hh;
        h.insert(-hh);
    }
    for (auto &tt:t) cin >> tt;
    for (int i = 0; i < m; i++) {
        auto it = h.lower_bound(-t[i]);
        if (it == h.end()) {
            cout << "-1\n";
            continue;
        } else {
            cout << -1 * *it << "\n"; 
            h.erase(it);
        }
    }

}

signed main() {
    solve();
    return 0;
}