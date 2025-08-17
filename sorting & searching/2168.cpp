#include<bits/stdc++.h>
using namespace std;


void solve() {
    int n; cin >> n;
    vector<pair<pair<int,int>,int>> a(n);
    for (int i = 0; i < n; i++) {cin >> a[i].first.first >> a[i].first.second;
    a[i].second = i;}
    vector<pair<pair<int,int>,int>> b(a.begin(),a.end());
    sort(a.begin(), a.end(), [](const auto &a, const auto &b){
        if (a.first.first != b.first.first) return a.first.first < b.first.first;
        else return a.first.second > b.first.second;
    }) ;

    sort(b.begin(), b.end(), [](const auto &a, const auto &b){
        if (a.first.second != b.first.second) return a.first.second > b.first.second;
        else return a.first.first < b.first.first;
    }) ;

    vector<int> contains(n), contained(n);

    int maxR = a[0].first.second;
    for (int i = 1; i < n; i++) {
        int r = a[i].first.second;
        int j = a[i].second;
        if (r > maxR) {
            maxR = r;
        } else {
            contained[j] = 1; 
        }
    }
    
    // print(b);
    int maxL = b[n-1].first.first;
    for (int i = n-2; i >= 0; i--) {
        int l = b[i].first.first;
        int j = b[i].second;
        if (maxL >= l) contains[j] = 1;
        maxL = max(maxL, l);
    }

    for (int i = 0; i < n; i++) cout << contains[i] << " \n"[i == n-1];
    for (int i = 0; i < n; i++) cout << contained[i] << " \n"[i == n-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}