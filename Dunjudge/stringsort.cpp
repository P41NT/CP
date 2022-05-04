#include <cctype>
#include <iostream>

using namespace std;

#define int long long int

int32_t main() {
    string s;
    getline(cin, s);

    string a1 = "", a2 = "";

    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i])) {
            if (isupper(s[i]))
                a1 += s[i];
            else
                a2 += s[i];
        }
    }

    cout << a1 << a2 << endl;
}
