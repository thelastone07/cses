#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto &aa : a) cin >> aa;
    map<long long, long long > mp;
    mp[0] = 1;
    vector<long long> subsum(n);
    subsum[0]=a[0];
    for (int i = 1; i < n; i++)subsum[i] = subsum[i-1] + a[i];
    long long  cnt = 0;
    for (int i = 0; i < n; i++) {
        long long target = subsum[i] - x;
        if (mp.count(target)) cnt+=mp[target];
        mp[subsum[i]]++;
    }
    cout << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}