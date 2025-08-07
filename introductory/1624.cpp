#include<bits/stdc++.h>
using namespace std;

char board[8][8];
int ans = 0;

bool col[8] = {false};
bool diag1[15] = {false};
bool diag2[15] = {false};

void track(int row) {
    if (row == 8) {
        ans++;
        return;
    }
    for (int c = 0; c <8; c++) {
        if (board[row][c] == '*')continue; 
        if (col[c] || diag1[row-c+7] || diag2[row+c]) continue; 

        col[c] = diag1[row-c+7] = diag2[row+c] = true;
        track(row+1);
        col[c] = diag1[row-c+7] = diag2[row+c] = false;  
    }
}

void solve() {
    for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++) 
    cin >> board[i][j];
    track(0);
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}