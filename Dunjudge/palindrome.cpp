#include <algorithm>
#include <iostream>

using namespace std;

string s, t;

#define int long long int

bool ispalindrome(int i) {
    s = t = to_string(i);

    reverse(t.begin(), t.end());
    return s == t;
}

int32_t main() {
    int start, end;
    cin >> start >> end;

    for (int i = start; i <= end; i++) {
        if (ispalindrome(i))
            cout << "Palindrome!" << endl;
        else
            cout << i << endl;
    }
}
