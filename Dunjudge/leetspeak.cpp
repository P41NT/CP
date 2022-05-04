#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    for (auto k : s) {
        if (!isalpha(k)) {
            cout << "l33t" << endl;
            return 0;
        }
    }

    cout << "English" << endl;
}
