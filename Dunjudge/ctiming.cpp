#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int k = 16511;

    int l = 24 * 60 * a + 60 * b + c;

    if (k > l)
        cout << -1 << endl;
    else
        cout << l - k << endl;
}
