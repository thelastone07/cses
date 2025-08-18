#include<bits/stdc++.h>
using namespace std;
 
void solve() {
    int n; cin >> n;
    long long dlSum = 0;
    vector<int> dur(n);
    vector<long long> subsum(n);
    for(int i = 0; i < n; i++) {
        int dl;
        cin >> dur[i] >> dl;
        dlSum += dl;
    }
    sort(dur.begin(), dur.end());
    subsum[0] = dur[0];
    for (int i = 1; i < n; i++) {
        subsum[i] = subsum[i-1] + dur[i];
    }
    long long durSum = accumulate(subsum.begin(), subsum.end(),0LL);
    cout << dlSum - durSum << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}