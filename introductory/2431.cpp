#include<bits/stdc++.h>
using namespace std;

long long power(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a = (a * a);
        b /= 2;
    }
    return res;
}

void solve() {
    int q; cin >> q;
    while (q--) {
        long long k;
        cin >> k;
        long long len = 1, count = 9, digits = len*count;
        while (k > digits) {
            k -= digits;
            len++;
            count *= 10;
            digits = len * count;
        }
        long long idx = k % len;

        long long res = power(10,(len-1)) + (k-1)/len;
        if (idx != 0) {
            res = res / power(10,len-idx);
        }
        cout << res % 10 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}