#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> v(n), idx(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i]--;
        idx[v[i]] = i;
    }
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (idx[i-1] > idx[i])ans++;
    }

    while (m--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        set<pair<int,int>> pairs;
        if (v[l] + 1 <= n-1) pairs.insert({v[l],v[l]+1});
        if (v[l] - 1 >= 0) pairs.insert({v[l]-1,v[l]});
        if (v[r] + 1 <= n-1) pairs.insert({v[r],v[r]+1});
        if (v[r] - 1 >= 0) pairs.insert({v[r]-1,v[r]});

        for (auto p : pairs)
        ans -= (idx[p.first] > idx[p.second] );

        idx[v[l]] = r;
        idx[v[r]] = l;
        swap(v[l],v[r]);

        for (auto p : pairs)
        ans += (idx[p.first] > idx[p.second]);

        cout << ans << '\n';
    }
}

signed main() {
    solve();
    return 0;
}