#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> v(n,vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1];
        v[i][2] = i;
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    sort(v.begin(), v.end());
    vector<int> ans(n);
    pq.push({v[0][1],1});
    ans[v[0][2]] = 1;
    for (int i = 1; i < n; i++) {
        int k = pq.size();
        auto [u,z] = pq.top();
        if (u <= v[i][0]) {
            pq.pop();
            pq.push({v[i][1],z});
            ans[v[i][2]] = z;
        }
        else {
            pq.push({v[i][1],k+1});
            ans[v[i][2]] = k + 1;
        }
    }
    for (int i =0;i < n; i++) cout << ans[i] << " ";
    cout << '\n';
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}