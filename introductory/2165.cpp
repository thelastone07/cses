#include<bits/stdc++.h>
using namespace std;

void hanoi(int n, int src, int aux, int des) {
    if (n == 1) {
        cout << src << " " << des << '\n';
        return;
    }
    hanoi(n-1, src, des, aux);
    cout << src << " " << des << "\n";
    hanoi(n-1, aux, src, des);
}

void solve() {
    int n; cin >> n; 
    cout << (1 << n) - 1 << '\n';
    hanoi(n,1,2,3);
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}