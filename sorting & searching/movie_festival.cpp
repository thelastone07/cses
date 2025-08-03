#include<bits/stdc++.h>
using namespace std;


void solve() {
    int n;
   cin >> n;
   vector<pair<int,int>> m;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        m.push_back({b,a});
    }
    sort(m.begin(),m.end());
    int cnt = 1;
    int idx = 0;
    for (int i = 1; i < n; i++) {
        if (m[idx].first <= m[i].second) {
            cnt++;
            idx = i;
        }
    }   
    cout << cnt << "\n";
}

signed main() {
    solve();return 0;
}