#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;

    cin >> n;

    map<string, int> mp;

    for (int i = 0; i < n; i++) {
        string s;
        int t;

        cin >> s >> t;
        mp[s] = t;
    }

    int m;
    cin >> m;
    int sum = 0;
    string st;
    for (int i = 0; i < m; i++) {
        cin >> st;
        sum += mp[st];
    }

    cout << (sum / m) << endl;
}
