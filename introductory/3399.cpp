#include<bits/stdc++.h>
using namespace std;

void print(vector<int> x){
    for (int i = 0; i <(int) x.size(); i++) cout << x[i] + 1 << " ";
    cout << '\n';
}

void solve() {
    int n, a, b; 
    cin >> n >> a >> b; 
    bool cond = (a + b == 0) || (a > 0 && b > 0 && a + b <=n);
    if (!cond) {cout << "NO\n";return;}
    bool swapped = false;
    if (b > a){ swap(a,b); swapped = true;}
    int eq = n - ( a + b);
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) A[i] = i;
// b wins initially
    if (b)
    for (int i = 0; i < b; i++) {
       B[i] = A[n-b + i];
    }
    // a wins at last
    if (a)
    for (int i = 0 ; i < a; i++) {
        B[n - a + i] = A[i];
    }
    // equal in bw after B wins
    for (int i = 0; i < eq; i++) {
        B[i+b] = A[i+b];
    }
    cout << "YES\n";
    if (a + b == 0) for (int i= 0; i < n ;i++) B[i] = i;
    if (swapped) {
        print(B); print(A);
    }
    else {
        print(A); print(B);
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin >> t;
    while(t--)
    solve();
    return 0;
}