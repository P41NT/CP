#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;

    cout << s << endl;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < i + 1; j++) {
            cout << " ";
        }

        cout << s[s.size() - 1 - i];
        for (int j = 0; j < s.size() - 2; j++) {
            cout << " ";
        }

        cout << s[i] << endl;
    }

    reverse(s.begin(), s.end());

    for (int i = 0; i <= s.size(); i++) {
        cout << " ";
    }
    cout << s << endl;
}
