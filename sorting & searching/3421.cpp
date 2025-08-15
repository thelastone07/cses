#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    unordered_map<int,int> mp;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        mp[x]++;
    }

    long long ans = 1;
    for (auto [k,cnt]:mp) {
        ans = (ans*(cnt+1)) % mod;
    }
    cout << (ans - 1 + mod) % mod << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}