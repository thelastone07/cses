#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> k(n);
    for (auto &kk : k) cin >> kk;
    multiset<int> t;
    t.insert(k[0]);
    int duplicates = 0;
    for (int i = 1; i < n; i++) {
        auto it = t.upper_bound(k[i]);
        if (it != t.end()) {
            // if (*it == k[i]) duplicates++;
            t.erase(it);}
        t.insert(k[i]);
    }
    cout << t.size() + duplicates << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}