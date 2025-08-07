#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto &pp : p) cin >> pp; 
    long long sum = accumulate(p.begin(),p.end(),0LL);
    long long mdiff = sum; 
    for(int mask = 0; mask < (1 << n); mask++) {
        long long subset = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i))
            subset += p[i];
        }
        mdiff = min(mdiff, abs((sum - subset) - subset));

    }
    cout << mdiff << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}