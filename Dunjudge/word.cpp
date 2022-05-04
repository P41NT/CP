#include <bits/stdc++.h>

using namespace std;

int main() {
    string raw;
    getline(cin, raw);
    raw.push_back(' ');
    int n = raw.size();
    for (int i = 0; i < n; i++) {
        if (!isalnum(raw[i])) raw[i] = ' ';
    }

    string::iterator ip = unique(raw.begin(), raw.end());

    raw.resize(distance(raw.begin(), ip));
    int ans = 0;
    for (int i = 1; i < raw.size(); i++) {
        if (raw[i] == ' ' && isalnum(raw[i - 1])) ans++;
    }
    cout << ans << endl;
}
