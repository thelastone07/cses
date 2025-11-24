#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

const int MOD = 1e9 + 7;
const int N = 20;

int main() {
    // Simulate the random access pattern of your DP
    vector<int> access_pattern;
    for (int mask = 1; mask < (1 << N); mask++) {
        for (int v = 0; v < N; v++) {
            if (!(mask & (1 << v))) {
                access_pattern.push_back(mask | (1 << v));
            }
        }
    }
    
    // Test with int
    vector<vector<int>> dp_int(1 << N, vector<int>(N, 1));
    auto start = high_resolution_clock::now();
    
    for (int iter = 0; iter < 10; iter++) {
        for (int idx : access_pattern) {
            for (int v = 0; v < N; v++) {
                dp_int[idx][v] = (dp_int[idx][v] + dp_int[idx/2][v]) % MOD;
            }
        }
    }
    
    auto end = high_resolution_clock::now();
    cout << "int (random access): " << duration_cast<milliseconds>(end - start).count() << " ms\n";
    
    // Test with long long
    vector<vector<long long>> dp_ll(1 << N, vector<long long>(N, 1));
    start = high_resolution_clock::now();
    
    for (int iter = 0; iter < 10; iter++) {
        for (int idx : access_pattern) {
            for (int v = 0; v < N; v++) {
                dp_ll[idx][v] = (dp_ll[idx][v] + dp_ll[idx/2][v]) % MOD;
            }
        }
    }
    
    end = high_resolution_clock::now();
    cout << "long long (random access): " << duration_cast<milliseconds>(end - start).count() << " ms\n";
}