#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (auto & xx : x) cin >> xx;
    vector<int> best(n+1);
    best[0] = 0;
    int ans = 0;
    for (int i = 0; i < n; i ++) {
        int len = lower_bound(best.begin(), best.begin()+ans+1,x[i]) - best.begin();
        if (len > ans) {
            ans = len;
            best[ans] = x[i];
        }
        else {
            best[len] = min(x[i], best[len]); 
        }
    }
    cout << ans << '\n';
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}