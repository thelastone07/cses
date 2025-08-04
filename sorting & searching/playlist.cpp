#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n ;
    vector<int> a(n);
    for (auto &aa : a) cin >> aa;

    int cnt = 1;
    int mx = 1;
    map<int,int> mp;
    mp[a[0]] = 0;
    for (int i = 1; i < n; i++) {
        if (mp.find(a[i]) != mp.end() && cnt >= (i - mp[a[i]])) {
            cnt = i - mp[a[i]];
        }
        else cnt++;
        mx = max(mx, cnt);
        mp[a[i]] = i;
    }
    cout << mx << '\n';
}

signed main(){
    solve();
    return 0;
}