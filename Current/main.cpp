#include <bits/stdc++.h>

using namespace std;

#define int long long int

int n;
bool possible = true;

map<int, int> mp;
int recur(int x) {
    if (mp.count(x)) return mp[x];
    string str = to_string(x);
    if (str.length() == n) return 0;
    if (str.length() > n) return -1;
    vector<int> p;
    for (auto s : str) {
        if (s > '1') {
            int sol = 1 + recur(x * (s - '0'));
            if (sol != -1) p.push_back(sol);
        }
    }
    if (p.size() == 0)
        return -1;
    else
        return mp[x] = *(min_element(p.begin(), p.end()));
}

// void solve() {
//     int n, x;
//     cin >> n >> x;
//
//     int counter = 0;
//     while (true) {
//         string temp = to_string(x);
//         int mx = *(max_element(temp.begin(), temp.end())) - '0';
//         int newx = x * mx;
//         counter++;
//         if (newx == x) {
//             cout << -1 << endl;
//             return;
//         }
//         if (to_string(newx).length() == n) {
//             break;
//         }
//         x = newx;
//
//     }
//     cout << counter << endl;
// }

void solve() {
    int x;
    cin >> n >> x;
    cout << recur(x) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("../Current/input.txt", "r", stdin);
    freopen("../Current/output.txt", "w", stdout);
#endif

    int t = 1;
    //    cin >> t;
    while (t--) {
        solve();
    }
}