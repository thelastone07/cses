#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    string ans = "";
    
    map<char,int> mp;
    vector<int> idx(26,1e6+7);
    for (char ch : s) mp[ch]++;

    int i = 0;
    auto it = mp.begin();
    bool go_back = false;
    while (it != mp.end()) {
        char key = it->first;
        int &val = it->second;

        if (val == 0) {
            ++it;
            continue;
        }
        val--;
        idx[val-'A'] = min(idx[val-'A'],i);
        i++;
        if (go_back) {
            it--;
        }
        else {
            if (val) go_back = true;
            it++;
        }

    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}