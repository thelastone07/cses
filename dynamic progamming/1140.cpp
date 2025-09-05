#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<vector<int>> days(n,vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> days[i][1] >> days[i][0] >> days[i][2];
    }
    sort(days.begin(), days.end());
    set<pair<int,long long int>> st;
    st.insert({days[0][0],days[0][2]});
    for (int i = 1; i < n; i++) {
        
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}