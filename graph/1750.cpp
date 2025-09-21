#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> suc(31,vector<int>(n+1));
    for (int i = 1; i <=n ; i++) {
        cin >> suc[0][i];
    }
    for (int i = 1; i <=30; i++) {
        for (int x = 1; x <= n; x++)
        suc[i][x] = suc[i-1][suc[i-1][x]];
    }
    while (q--) {
        int x, k;
        cin >> x >> k;
        for (int i = 0; i <=30; i++) {
            if (k & (1 << i))
            x = suc[i][x];
        }
        cout << x <<'\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}