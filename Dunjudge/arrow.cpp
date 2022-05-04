#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int k = (n + 1) / 2 - 1;
    int l = m - k;

    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        for (int i = 0; i < l; i++) {
            cout << "*";
        }

        for (int j = l + i; j < m; j++) {
            cout << " ";
        }
        cout << endl;
    }

    for (int i = k - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        for (int i = 0; i < l; i++) {
            cout << "*";
        }

        for (int j = l + i; j < m; j++) {
            cout << " ";
        }
        if (i != 0) cout << endl;
    }
}
