#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= n;{
            
        }
        a[i] = (a[i] + n) % n;
    }
    map<int, long long> mp;
    mp[0] = 1;
    vector<int> subsum(n);
    subsum[0] = a[0];
    for (int i = 0; i < n; i++) {
        subsum[i] = (subsum[i-1] + a[i])%n;
    }
    long long cnt = 0;
    for (int i = 0; i< n; i++) {
        int target = (subsum[i]) % n;;
        if (mp.count(target)) {
            cnt += mp[target];
            // cout << i << " " << target <<" " << mp[target]<< " \n";
        }
        mp[subsum[i]]++;
    }
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}