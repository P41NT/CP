#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;
        string ans = "";
        ans += s[0];
        for (int i = 1; i < s.size() - 1; i++) {
            if (s[i] == '_') ans += s[i + 1];
        }
        cout << (ans.size() > 5 ? "CENSORED" : ans) << endl;
    }
}
