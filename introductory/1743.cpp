#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> freq(26,0);
    for (char c : s) freq[c-'A']++;

    int maxFreq = *max_element(freq.begin(), freq.end());

    if (maxFreq > (n+1)/2) {
        cout << -1 << '\n';
        return;
    }

    string result;
    result.reserve(n);
    char last = '\0';

    for (int i = 0; i < n; i++) {
        int choice = -1;
        for (int c = 0; c < 26; c++) {
            if (freq[c] == 0) continue;
            if (last == char('A' + c)) continue;

            freq[c]--;
            int remaining = n - (i + 1);
            int futureMax = *max_element(freq.begin(), freq.end());
            if (futureMax <= (remaining+1)/2) {
                choice = c;
                break;
            }
            freq[c]++;
        }
        if (choice == -1) {
            cout << -1 << '\n';
            return;
        }
        result.push_back('A' + choice);
        last = 'A' + choice;
    }
    cout << result << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}