#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >>n;
    vector<int> x(n);
    for (auto &xx : x) cin >> xx;
    int sum = accumulate(x.begin(),x.end(),0);;
    vector<bool> dp(sum+1,false);
    sort(x.begin(),x.end());
    dp[0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = sum; j >=x[i]; j--) {
            if (dp[j-x[i]])dp[j] = true;
        }
    }
    vector<int> nums;
    for (int i = 1; i <=sum;i++ ){if (dp[i])nums.push_back(i);}
    cout << nums.size() << '\n';
    for (auto k : nums) cout << k << " ";
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}