#include <bits/stdc++.h>
using namespace std;


int min_operations(const vector<int>& a, int n) {
    int segments = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != 0) {
            segments++;
            while (i < n && a[i] != 0) {
                i++;
            }
        }
    }
    
    return min(segments, 2);
}

int main() {
    int t;
    cin >> t; 

    while (t--) {
        int n;
        cin >> n; 

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; 
        }
        cout << min_operations(a, n) << endl;
    }

    return 0;
}
