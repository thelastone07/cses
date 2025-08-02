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
    
}

signed main() {
    solve();return 0;
}