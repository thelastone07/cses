#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (auto &xx : x) cin >> xx;
    unordered_map<int,int> last;
    vector<int> dp(n+1,0);
    dp[0] = 2;
    last[x[0]] = 0;
    for (int i = 1; i < n; i++){
        dp[i] =  (2LL * dp[i]) % mod;
        if (last.count(x[i])) {
            int j = last[x[i]];
           if (j > 0) {
            dp[i] = (dp[i] - dp[j-1] + mod) % mod;
           }
           else {
            dp[i] = (dp[i] - 1 + mod) % mod;
           }
        }
        last[x[i]] = i;
    }
    cout << (dp[n-1] - 1 + mod) % mod << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}