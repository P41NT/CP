//
// Created by p41nt on 24/5/22.
//
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

inline bool cmp(pair<int, string> a, pair<int, string> b) {
    if (a.first != b.first) {
        return a.first > b.first;
    } else {
        return a.second.compare(b.second) < 0;
    }
}

void solve() {
    // code goes here

    int n;
    cin >> n;

    vector<pair<int, string>> arr;

    for (int i = 0; i < n; i++) {
        string person, class_, ending;
        cin >> person >> class_ >> ending;

        string curr_ = "";
        int curr = 0;

        string token;
        istringstream ss(class_);

        while (std::getline(ss, token, '-')) {
            if (token.compare("upper") == 0) {
                curr_.push_back('3');

            } else if (token.compare("middle") == 0) {
                curr_.push_back('2');
            } else if (token.compare("lower") == 0) {
                curr_.push_back('1');
            }
        }
        curr_ = string(curr_.rbegin(), curr_.rend());
        while (curr_.length() != 10) curr_.push_back('2');

        int curr_value = stoll(curr_);

        arr.push_back({curr_value, person.substr(0, person.length() - 1)});
    }

    sort(arr.begin(), arr.end(), cmp);

    for (auto s : arr) {
        cout << s.second << endl;
    }

    cout << "==============================" << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("../Current/input.txt", "r", stdin);
    freopen("../Current/output.txt", "w", stdout);
#endif

    //================================================================
    int t;
    t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    //================================================================

    return 0;
}
