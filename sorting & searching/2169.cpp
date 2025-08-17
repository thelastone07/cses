#include<bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<int> bit;

    BIT (int n) : n(n), bit(n+1,0) {}

    void add (int i, int val) {
        for (++i; i <= n; i += i & -i ) bit[i] += val;
    }
    int sum (int i) {
        int res = 0;
        for (++i; i > 0; i -= i & -i) res += bit[i];
        return res;
    }
    int count(int l, int r) {
        return sum(r) - (l? sum(l-1) : 0);
    }
};

void print(vector<pair<pair<int,int>,int>> p) {
    for (auto [v,i]:p) {
        cout << v.first << " " << v.second << " " << i << '\n';
    }
}


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
    // print(a);
    vector<int> aa;
    for (auto [v,i]:a) {
        aa.push_back(v.second);
    }
    vector<int> val = aa;
    sort(val.begin(),val.end());
    val.erase(unique(val.begin(),val.end()),val.end());
    auto getIdd = [&](int x) {
        return int(lower_bound(val.begin(),val.end(),x)-val.begin());
    };
    BIT bit1(val.size());
    for (int i = 0; i < n; i++) {
        int id = getIdd(aa[i]);
        int idx = a[i].second;
        contained[idx] = bit1.count(id,val.size()-1);
        bit1.add(id,1);
    }
    
    // print(b);
    vector<int> bb;
    for (auto [v , i] : b) {bb.push_back(v.first);}
    vector<int> vals = bb;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(),vals.end()),vals.end());
    auto getId = [&](int x) {
        
        return int(lower_bound(vals.begin(), vals.end(),x)-vals.begin());
    };

    BIT bit2(vals.size());
    for (int i = n-1; i >= 0; i--) {
        int id = getId(bb[i]);
        int idx = b[i].second;
        contains[idx] = bit2.count(id,vals.size()-1);
        bit2.add(id,1);
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