#include<bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    vector<long long> factors;
    for (long long i = 5; i <= n; i = i*5) factors.push_back(i);
    long long ans = 0; 
    for (auto f : factors) ans += (n / f);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}