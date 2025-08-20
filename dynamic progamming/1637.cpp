#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> dp(n+1,1e9);
    
    function<int(int)> fill =[&](int x)->int {
        if (x == 0) return 0;
        if (dp[x]!=1e9) return dp[x];
        string s = to_string(x);
        for (int i = 0; i < s.size(); i++) {
            int d = s[i] - '0';
            if (x - d >= 0)
            {int ux = x - d;
            dp[x] = min(dp[x], 1+fill(ux));}
        }
        return dp[x];
    };

    fill(n);
    cout << dp[n] ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}