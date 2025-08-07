#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;

    sort(s.begin(), s.end()); // Start with smallest lex order
    vector<string> results;

    do {
        results.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << results.size() << "\n";
    for (const string& perm : results) {
        cout << perm << "\n";
    }

    return 0;
}
