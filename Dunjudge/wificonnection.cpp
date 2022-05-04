#include <iostream>

using namespace std;

#define int long long int

int32_t main() {
    int n, k;
    cin >> n >> k;
    int counter = 0;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        if (k * k >= a * a + b * b) counter++;
    }

    cout << counter << endl;
}
