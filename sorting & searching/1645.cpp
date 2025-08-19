#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    stack<int> st;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0) {cout << 0 << " "; st.push(0); continue;}
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        if (st.empty()) cout << 0 << " ";
        else cout << st.top() + 1 << " ";
        st.push(i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}