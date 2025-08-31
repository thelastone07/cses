#include<bits/stdc++.h>
using namespace std;

/*
don't understand the test case.
if you can go either side then the answer should be 6 when 
travelling from 40.
*/


void solve() {
    int n; cin >> n;
    vector<int> h(n);
    for (auto &hh : h) cin >> hh;
    stack<pair<int,int>> st;
    vector<int> dp(n);
    for (int i = n-1; i >= 0; i--) {
        while (!st.empty() && (h[i] > st.top().first)) st.pop();
        if (st.empty()) dp[i] = n - i;
        else {
            auto [x,idx] = st.top();
            dp[i] = idx - i ;
        }
        st.push({h[i],i});
    }
    int mx = *max_element(dp.begin(),dp.end());
    reverse(h.begin(),h.end());
    st = stack<pair<int,int>>();
    for (int i = n-1; i >= 0; i--) {
        while (!st.empty() && (h[i] > st.top().first)) st.pop();
        if (st.empty()) dp[i] = n - i;
        else {
            auto [x,idx] = st.top();
            dp[i] = idx - i ;
        }
        st.push({h[i],i});
    }
    mx = max(mx, *max_element(dp.begin(),dp.end()));
    cout << mx ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}