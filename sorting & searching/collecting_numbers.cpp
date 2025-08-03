#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &aa : a) cin >> aa;
    map<int,int> mp;
    for (int i= 0; i < n; i++) {
        if (mp[a[i]-1]) {
            mp.erase(a[i]-1);
        }
        mp[a[i]]++;
    }
    
    cout << mp.size() - 1 << '\n';
}

signed main(){
    solve();
    return 0;
}