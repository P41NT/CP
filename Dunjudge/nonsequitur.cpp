#include <iostream>

using namespace std;

#define int long long int

int32_t main() {
    int n, s, t;
    cin >> n >> s >> t;

    for (int i = s; i <= t; i++) {
        if (i % n == 0) {
            cout << i << endl;
        }
    }
}
