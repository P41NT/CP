#include <string.h>

#include <iostream>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    string ans = "";
    int n;
    cin >> n;

    for (int i = 0; i < a.size(); i += n) {
        ans += a.substr(i, n);
        ans += b.substr(i, n);
    }
    cout << ans << endl;
}
