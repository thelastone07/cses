#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n; 

    vector<vector<int>> grid(n,vector<int>(n,0));
   

    auto mex = [&](int r, int c) {
        vector<int> present(2*n+1,false);
        for (int i = 0; i < c; i++) {
            present[grid[r][i]] = true;
        }
        for (int i = 0; i < r; i++) {
            present[grid[i][c]] = true;
        }
        for (int i = 0; i < 2*n; i++) if (!present[i]) return i;
        return 2*n;
    };
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int ans = mex(i,j);
            cout << ans << " ";
            grid[i][j] = ans;   
        }
        cout << '\n';
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}