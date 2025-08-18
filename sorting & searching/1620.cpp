#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, t;
    cin >> n >> t;
    vector<int> k(n);
    for (auto &kk : k) cin >> kk;
    int minEle = *min_element(k.begin(),k.end());
    long long l = 0, r = minEle * t;
    long long ans = 1e18;
    auto check = [&](long long x) {
        long long cnt = 0;
        for (auto kk : k) {cnt += x / kk; if (cnt >= t) return true;}
        return (cnt >= t);
    };
    while (r >= l) {
        long long mid = (r + l) / 2;
        if (check(mid)) {
            ans = min(ans,mid);
            r = mid-1;
        }
        else l = mid + 1;
    }
    cout << ans ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}