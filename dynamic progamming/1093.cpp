#include<bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

void solve() {
    int n; cin >> n;
    int x = n * (n + 1) / 2;
    if (x % 2) {cout << 0; return;}
    x /= 2;
    vector<long long> dp(x+1);
    dp[0] = 1;
    for (int i = n; i >= 1; i--) {
        for (int sum = x; sum >= 0; sum--) 
        if (sum - i >= 0 ) 
        dp[sum] = (dp[sum] + dp[sum-i]) % mod;
    }
    int inv2 = (mod + 1) / 2;
    cout << dp[x] *inv2 % mod<< '\n';
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}   