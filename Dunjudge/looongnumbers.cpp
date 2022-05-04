#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    if (a.length() > b.length()) swap(a, b);

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string ans = "";

    int carry = 0;
    for (int i = 0; i < a.length(); i++) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        ans.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    for (int i = a.length(); i < b.length(); i++) {
        int sum = (b[i] - '0') + carry;
        ans.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    if (carry) {
        ans.push_back(carry + '0');
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}
