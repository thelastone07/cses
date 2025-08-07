 #include<bits/stdc++.h>
using namespace std;

void solve() {
    int t; cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b; 
        if (b > a) swap(a,b);
        if (a == b) {
            if ( a % 3 == 0) cout << "YES\n";
            else cout << "NO\n";
            continue;
        }
        int diff = a - b; 
        int val = b - diff;
        if (val % 3 == 0 && val >= 0) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}