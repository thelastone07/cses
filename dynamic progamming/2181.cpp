#include<bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;

    swap(n,m);
    if (n == 1 || m ==1) {
        cout << 1;
        return;
    }
    vector<bitset<10>> perms;
    for (int i = 0;  i < (1 << m); i++) {
        bitset<10> s(i),t;
        t = (1 << m) - 1;
        perms.push_back(s&t);
    }
    vector<vector<int>> dp(n, vector<int>(perms.size(),0));

    int sz = perms.size();

    for (int i = 0; i < sz; i++) {
        auto perm = perms[i];
        if (perm.count() % 2) dp[0][i] = 1;
    }

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < sz; j++) {
            auto perm1 = perms[j];
            for (int k = 0; k < sz; k++) {
                auto perm2 = perms[k];
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}