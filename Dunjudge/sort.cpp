#include <string.h>

#include <algorithm>
#include <iostream>

using namespace std;

inline bool compare(string a, string b) {
    if (a.length() == b.length()) return a < b;
    return a.length() < b.length();
}

int main() {
    int n;
    cin >> n;

    string arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n, compare);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
