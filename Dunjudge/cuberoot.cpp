#include <math.h>

#include <iostream>

#define int long long int

using namespace std;

int32_t main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        cout << cbrt(t) << endl;
    }
}
