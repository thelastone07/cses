#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n; 
    for (int i = 0; i < (1 << n); i++) {
        int val = i ^ (i >> 1);
        cout << bitset<16>(val).to_string().substr(16-n) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}