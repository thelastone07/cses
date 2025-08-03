#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> x(n);
    for (auto &xx :x) cin >> xx;
    sort(x.begin(), x.end());
    long long int fill = 0;
    for (int i = 0; i < n ;i++) {
        if (x[i] > fill+1) {cout << fill + 1 << "\n";return;}
        else fill += x[i];
    }
    cout << fill + 1 << '\n';
}

signed main() {
    solve(); return 0;
}