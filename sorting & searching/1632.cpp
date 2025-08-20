#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> a(n);
    for (auto &aa : a) cin >> aa.first >> aa.second;

    // sort by end time
    sort(a.begin(), a.end(), [](auto &x, auto &y) {
        if (x.second != y.second) return x.second < y.second;
        return x.first < y.first;
    });

    multiset<int> watchers; 
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        int st = a[i].first, en = a[i].second;

        auto it = watchers.upper_bound(st);
        if (it != watchers.begin()) {
            --it;
            watchers.erase(it);
            watchers.insert(en);
            cnt++;
        } else if ((int)watchers.size() < k) {
            watchers.insert(en);
            cnt++;
        }
    }
    cout << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
