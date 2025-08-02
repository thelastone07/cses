#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> q;
    for (int i = 0; i <n; i++) {
        int a, b;
        cin >> a >> b;
        q.push_back({a,0});
        q.push_back({b,1});
    }
    sort(q.begin(),q.end());
    int cnt = 0, c = 0;
    for (auto [a, flag]:q) {
        if (flag == 0) c++;
        else c--;
        cnt = max(cnt,c);
    }
    cout << cnt << '\n';
}

signed main() {
    solve();
    return 0;
}