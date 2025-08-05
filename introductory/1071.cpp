#include<bits/stdc++.h>
using namespace std;

void solve(){
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        long long n = max(r,c);
        long long first = (n-1)*(n-1) + 1;
        long long last = (n-1)*(n-1) + 2*n - 1;

        if (first % 2 == 0) swap(r,c);
        if (r == n) {
            cout << first + c - 1 << '\n';
        }
        else {
            cout << last - r + 1 << "\n";
        }
    }
}

signed main() {
    solve();
    return 0;
}