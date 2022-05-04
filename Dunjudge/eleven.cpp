#include <iostream>

using namespace std;

int main() {
    string n;
    cin >> n;
    int a = 0, b = 0;

    for (int i = 0; i < n.length(); i++) {
        if (i & 1)
            a += n[i] - '0';
        else
            b += n[i] - '0';
    }

    if (abs(a - b) % 11 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
