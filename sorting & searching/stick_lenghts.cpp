#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto &pp:p) cin >> pp;
    sort(p.begin(), p.end());
    int val = 0;
    if (n%2==1) val = p[n/2];
    else val = (int)floor((p[n/2] + p[n/2-1])/2);
    long long int ans = 0;
    for (auto v : p) ans += abs(val - v);
    cout << ans << '\n';
}

signed main() {
    solve(); return 0;
}