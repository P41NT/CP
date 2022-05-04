#include <math.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define int long long int

int32_t main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    cout << x[ceil(n / 2.0) - 1] << " " << y[ceil(n / 2.0) - 1] << endl;
}
