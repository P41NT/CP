#include <algorithm>
#include <iostream>

using namespace std;

#define int long long int

int32_t main() {
    int a, b;
    cin >> a >> b;

    int g = __gcd(a, b);

    cout << (a / g) << "/" << (b / g) << endl;
}
