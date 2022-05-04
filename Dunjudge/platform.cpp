#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < (n - i - 1); k++) {
            cout << " ";
        }
        cout << '/';
        for (int k = 0; k < 2 * i; k++) {
            cout << " ";
        }
        cout << "\\";

        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < i; k++) {
            cout << " ";
        }
        cout << "\\";
        for (int k = 0; k < 2 * (n - i - 1); k++) {
            cout << " ";
        }
        cout << "/";
        cout << endl;
    }
}
