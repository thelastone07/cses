#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;
    long long n = s.size();
    long long cnt = 1, mx = 1;
    for (int i = 1;i  < n; i++) {
        if (s[i] == s[i-1]) cnt++;
        else cnt = 1;
        mx = max(cnt,mx);
    }
    cout << mx << "\n";
}

signed main() {
    solve();
    return 0;
}