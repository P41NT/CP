#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

#define int long long int
#define endl "\n"

bool isValid(string st) {
    for (int i = 1; i <= 6; i++) {
        if (st[i] >= 'A' && st[i] <= 'F') continue;
        if (st[i] >= '0' && st[i] <= '9') continue;
        return false;
    }
    return true;
}

int32_t main() {
    int n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;
        if (isValid(s))
            cout << "Hexadecimal" << endl;
        else
            cout << "Not Hexadecimal" << endl;
    }
}
