#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &aa : a)cin >> aa;
    cout << set<int>(a.begin(),a.end()).size() << '\n';
}

signed main() {
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}