#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>

using namespace std;

// Function to check if it's possible to arrange with max sum ≤ t
bool can(deque<int> pos_deque, deque<int> neg_deque, int t) {
    int s = 0, m = 0;

    while (!pos_deque.empty() || !neg_deque.empty()) {
        // Try to add positive elements without exceeding t
        while (!pos_deque.empty() && s + pos_deque.front() > t) {
            if (!neg_deque.empty()) {
                s += neg_deque.front();
                neg_deque.pop_front();
                m = max(m, s);
            } else {
                return false;
            }
        }
        if (!pos_deque.empty()) {
            s += pos_deque.front();
            pos_deque.pop_front();
            m = max(m, s);
        }
    }

    // Process remaining negatives
    while (!neg_deque.empty()) {
        s += neg_deque.front();
        neg_deque.pop_front();
        m = max(m, s);
    }

    return m <= t;
}

// Function to minimize the maximum subarray sum
int min_max_subarray_sum(const vector<int>& A) {
    // Separate positive and negative numbers
    deque<int> pos, neg;
    for (int x : A) {
        if (x >= 0) pos.push_back(x);
        else neg.push_back(x);
    }

    // Binary search on the answer
    int low = max(*max_element(pos.begin(), pos.end()), abs(accumulate(neg.begin(), neg.end(), 0)));
    int high = accumulate(A.begin(), A.end(), 0);
    int answer = high;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (can(pos, neg, mid)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return answer;
}

// Main function to handle multiple test cases
int main() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int n;
        cin >> n; // Length of the array

        vector<int> A(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i]; // The array elements
        }

        cout << min_max_subarray_sum(A) << endl; // Output the result for this test case
    }

    return 0;
}
