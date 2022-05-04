#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int jacket = 0, ranald = 0;
    for (int i = 0; i < s.size() - 6; i++) {
        string curr = s.substr(i, 6);
        if (curr == "JACKET")
            jacket++;
        else if (curr == "RANALD")
            ranald++;
    }

    cout << ((ranald >= jacket) ? "RANALD" : "JACKET") << endl;
}
