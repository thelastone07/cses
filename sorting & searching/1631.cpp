#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> t(n);
    for (auto &tt : t) cin >> tt;
    int mx = *max_element(t.begin(), t.end());
    long long sum = accumulate(t.begin(), t.end(),0LL);
    if (mx >= (sum-mx)) {
        cout << 2 * mx << '\n';
    } 
    else {
        cout << sum << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}