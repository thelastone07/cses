#include<bits/stdc++.h>
using namespace std;
vector<int> x;
vector<vector<long long>> dp;
int n;
 
long long fill(int l, int r) {
    if (l > r || l >=n || r < 0) return 0;
    if (l == r)return dp[l][r] = x[l];
    if (dp[l][r] != -1) return dp[l][r];
    long long ans = 0;
    ans = max(x[l]-fill(l+1,r), x[r]-fill(l,r-1));
    return dp[l][r] = ans;
}
 
void solve() {
    cin >> n;
    x.resize(n);
    for (auto &xx : x) cin >> xx;
    dp.resize(n+1,vector<long long>(n+1,-1));
    cout << (fill(0,n-1) + accumulate(x.begin(),x.end(),0LL)) / 2;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}