#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int last = 0;
    cin >> last;
    long long cnt = 0;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        cnt += max(0, last - x);
        last = x + max(0, last - x);
    }
    cout << cnt << '\n';
}

signed main() {
    solve();
    return 0;
}