#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    string ans = "";

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        if (input == "ADD_BACK") {
            char c;
            cin >> c;
            ans += c;
        } else if (input == "ADD_FRONT") {
            char c;
            cin >> c;
            ans = c + ans;
        } else if (input == "SNIP_FRONT") {
            int k;
            cin >> k;
            ans = ans.substr(k + 1);
        } else if (input == "SNIP_BACK") {
            int k;
            cin >> k;
            ans = ans.substr(0, k);
        } else {
            int k;
            cin >> k;
            cout << ans[k] << endl;
        }
    }
}
