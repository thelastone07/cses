#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(26,0);
    for (int i = 0; i < n; i++) {
        char ch = s[i];
        a[ch-'A']++;
    }
    int odd = 0; 
    for (int i = 0; i < 26; i++) if (a[i]%2)odd++;
    if (odd >=2) {
        cout << "NO SOLUTION\n";
        return;
    }
    int idx = -1; 
    for (int i = 0; i < 26; i++) {
        if (a[i] % 2) {
            idx = i;
            continue; 
        }
        char c = i + 'A';
        int cnt = a[i] / 2;
        while (cnt--) cout << c;
    }
    if (odd) {
        char c = idx + 'A';
        int cnt = a[idx];
        while(cnt--) cout << c;
    }
    for (int i = 25; i >= 0; i--) {
        if (a[i] % 2) {
            continue; 
        }
        char c = i + 'A';
        int cnt = a[i] / 2;
        while (cnt--) cout << c;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}