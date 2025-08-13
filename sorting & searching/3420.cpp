#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (auto &xx : x) cin >> xx;
    unordered_map<int,int> last;
    long long ans = 0;
    int left = 0;
    for (int r = 0; r < n; r++) {
        if (last.count(x[r])) {
            left = max(left, last[x[r]]+1);
        }
        last[x[r]] = r;
        ans += (r - left + 1);
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}