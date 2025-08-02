#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for(auto &aa:a) cin >> aa;
    for(auto &bb:b) cin >> bb;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 0;

    int i = 0, j = 0;
    while(i < n && j < m) {
        if (b[j]-k <= a[i] && a[i] <= b[j] + k) {
            ans++;
            i++;
            j++;
        }
        else if (a[i] > b[j] + k) {
            j++;
        }
        else i++;
    }
    cout << ans << '\n';
}

signed main() {
    solve();
    return 0;
}