//
// Created by p41nt on 16/6/22.
//
#include <bits/stdc++.h>
using namespace std;

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x) {
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(stack<T> &x, int f = 0) {
    cerr << (!f ? "{" : "");
    if (x.empty()) {
        cerr << '}';
        return;
    }
    auto k = x.top();
    x.pop();
    cerr << (f++ ? "," : "");
    __print(k);
    __print(x, f);
    x.push(k);
}
template <typename T>
void __print(const T &x) {
    int f = 0;
    cerr << '{';
    for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
    __print(t);
    if (sizeof...(v)) cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

#define int long long int
#define endl "\n"

vector<int> digits(10);
vector<string> sumup;

void precalc() {
    sumup.push_back("003");
    sumup.push_back("012");
    sumup.push_back("111");
    for (int i = 100; i < 1000; i++) {
        if (i / 100 + (i / 10 % 10) + i % 10 == 13)
            sumup.push_back(to_string(i));
        if (i / 100 + (i / 10 % 10) + i % 10 == 23)
            sumup.push_back(to_string(i));
        if (i / 100 + (i / 10 % 10) + i % 10 == 3)
            sumup.push_back(to_string(i));
    }
}

bool possible(string s) {
    vector<int> dig(10);

    for (int i = 0; i < 3; i++) {
        dig[s[i] - '0']++;
    }

    for (int i = 0; i < 10; i++) {
        if (dig[i] > digits[i]) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < 10; i++) digits[i] = 0;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] = arr[i] % 10;
        digits[arr[i]]++;
    }

    for (string s : sumup) {
        if (possible(s)) {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("../Current/input.txt", "r", stdin);
    freopen("../Current/output.txt", "w", stdout);
    freopen("../Current/error.txt", "w", stderr);
#endif

    //================================================================
    int t;
    precalc();
    cin >> t;
    while (t--) {
        solve();
    }
    //================================================================

    return 0;
}