#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    long long sum = 1LL* n * (n+1) / 2;
    if (sum % 2) {
        cout << "NO";
        return;
    }
    cout << "YES\n";
    sum = sum / 2 ;
    vector<int> a(n+1);
    
    for (int i = n; i >= 1; i--) {
        if (sum >= i) {
            a[i] = 1;
            sum -= i;
        }
    }
    int cnt =  accumulate(a.begin(),a.end(),0);
    cout << cnt << '\n';
    for (int i = 1; i <=n; i++) if (a[i]) cout << i << " ";
    cout << '\n';
    cout << n - cnt << '\n';
    for (int i = 1; i <=n; i++) if (!a[i]) cout << i << " ";
    cout << '\n';
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}