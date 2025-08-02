#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> p(n);
    for (auto &pp:p) cin >> pp;
    sort(p.begin(),p.end());
    int i = 0, j = n-1, ans = 0;
    while (j > i) {
        if (p[j] + p[i] <= x) {
            j--; i++;
        }
        else {
            j--;
        }
        ans++;
    }
    if (j == i) ans++;
    cout << ans << '\n';
}

signed main() {
    solve();
    return 0;
}