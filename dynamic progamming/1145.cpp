#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &aa : a) cin >> aa;

    vector<int> greater(n);
    stack<pair<int,int>> st;
    for (int i = n-1; i >= 0; i--){
        while (!st.empty() && a[i] >= st.top().first) st.pop();
        if (st.empty()) greater[i] = i;
        else greater[i] = st.top().second;
        st.push({a[i],i});
    }

    vector<int> dp(n);
    dp[n-1] = 1;
    for (int i = n-2; i >= 0; i--) {
        dp[i] = 1 + dp[greater[i]];
    }
    cout << *max_element(dp.begin(),dp.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}