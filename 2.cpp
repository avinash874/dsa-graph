// def can_alice_win(n,a,b):
// distance = abs(a-b)
// if distance % 2 == 0;
// return "YES"
// else:
// return "NO"

// t = int(input().strip())

// for_in range(t);
// n,a,b= map(int,input().strip().split())
// print(can_alice_win(n,a,b))

#include <bits/stdc++.h> 
using namespace std;

string alice_win(int n, int a, int b) {
    int distance = abs(a - b);
    if (distance % 2 == 0) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    int t;
    cin >> t; 

    while (t--) {
        int n, a, b;
        cin >> n >> a >> b; 
        cout << alice_win(n, a, b) << endl; 
    }

    return 0;
}
