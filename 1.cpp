#include <bits/stdc++.h>
using namespace std;

// Function to calculate inversions in the string
int calculate_inversions(const string& s) {
    int zeros = 0;
    int inversions = 0;

    // Traverse the string in reverse to calculate inversions
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == '0') {
            zeros++;
        } else {
            inversions += zeros;
        }
    }
    return inversions;
}

// Function to determine the minimum number of operations
int min_operations(int n, int x, int k, const string& s) {
    int total_inversions = calculate_inversions(s);

    // If the total inversions satisfy the constraints, return 1 operation
    if (total_inversions <= x && total_inversions % k == 0) {
        return 1;
    } else {
        return 2; // Otherwise, 2 operations are required
    }
}

int main() {
    int t;
    cin >> t; // Number of test cases
    vector<int> results;

    while (t--) {
        int n, x, k;
        cin >> n >> x >> k;
        string s;
        cin >> s;

        // Append the result for this test case
        results.push_back(min_operations(n, x, k, s));
    }

    // Output all results
    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}
