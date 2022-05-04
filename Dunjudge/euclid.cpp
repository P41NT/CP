#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (a == b) return b;

    return gcd(max(a, b) - min(a, b), min(a, b));
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << gcd(n, m) << endl;
}
