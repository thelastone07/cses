#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    for (long long k = 1; k <= n; ++k) {
        long long total_positions = k * k;
        long long total_pairs = total_positions * (total_positions - 1) / 2;
        long long attacking_pairs = 4 * (k - 1) * (k - 2);
        cout << total_pairs - attacking_pairs << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
