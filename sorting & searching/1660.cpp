#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto &aa :a) cin >> aa;
    int cnt = 0;
    long long sum = 0;
    int i = 0, j = 0;
    while (j < n) {
        while (j < n && sum + a[j] < x) {
            sum+=a[j]; 
            j++;
        } 
        if (j < n) {
            sum += a[j];
            j++;
        }
        if (sum == x) cnt++;
        while (i <= j && i < n && sum > x) {
            sum -= a[i];
            i++;
            if (sum == x) cnt++;
        }
    }
    while ( i < n) {
        sum -= a[i];
        i++;
        if (sum == x) cnt++;
    }
    cout << cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}