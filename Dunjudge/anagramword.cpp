#include <cctype>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

#define int long long int
#define endl "\n"

bool checkequal(vector<int>& first, vector<int>& second) {
    for (int i = 0; i < 26; i++) {
        if (first[i] != second[i]) return false;
    }

    return true;
}

int32_t main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    vector<int> first(26), second(26);

    for (int i = 0; i < s1.length(); i++) {
        if (!isalpha(s1[i])) continue;
        char ch = tolower(s1[i]);
        first[ch - 'a']++;
    }

    for (int i = 0; i < s2.length(); i++) {
        if (!isalpha(s2[i])) continue;
        char ch = tolower(s2[i]);
        second[ch - 'a']++;
    }

    if (!checkequal(first, second))
        cout << "NO" << endl;

    else
        cout << "YES" << endl;
}
