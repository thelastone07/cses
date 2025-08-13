#include<bits/stdc++.h>
using namespace std;

void solve() {
    int x, n;
    cin >> x >> n;
    set<int> cuts = {0,x};
    multiset<int> lengths = {x};
    
    while (n--) {
        int p; cin >> p;
        auto it = cuts.lower_bound(p);
        int right = *it;
        int left = *prev(it);
        cuts.insert(p);

        auto lenIt = lengths.find(right-left);
        lengths.erase(lenIt);

        lengths.insert(p-left);
        lengths.insert(right-p);

        cout << *lengths.rbegin() << " ";
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}