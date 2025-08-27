#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<float>> dp){ 

    for (auto dd : dp) {
        for (auto pp : dd) cout << pp << " ";
        cout << '\n';
    }
}

void solve() {
    int n; cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    
    vector<vector<int>> vis(n,vector<int>(n,-1));
    string ans;
    queue<pair<int,int>> candidates;
    candidates.push({0,0});
    ans.push_back(s[0][0]);
    for (int i = 0; i < 2*n-2;i++) {
        int lowest = 27;
        queue<pair<int,int>> newCandis;
        while(!candidates.empty()) {
            auto [x,y] = candidates.front();
            candidates.pop();
            if (vis[x][y] != -1) continue;
            queue<pair<int,int>> empty;
            if (x+1 < n) {
                if (lowest >= (s[x+1][y]-'A')) {
                    if (lowest > (s[x+1][y]-'A'))
                    newCandis = empty;
                    lowest = s[x+1][y];
                    newCandis.push({x+1,y});
                }
            }
            if (y+1 < n) {
                if (lowest >= (s[x][y+1]-'A')) {
                    if (lowest > (s[x][y+1]-'A'))
                    newCandis = empty;
                    lowest = s[x][y+1];
                    newCandis.push({x,y+1});
                }
            }
        }
        ans.push_back((char)(lowest+'A'));
        candidates = newCandis;
    }
    
    
    cout << ans ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}