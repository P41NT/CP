//
// Created by p41nt on 25/5/22.
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

void solve() {
    int n;
    cin >> n;

    n *= 2;

    stack<int> s1, s2;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s2.push(x);
    }

    while (!s2.empty()) {
        s1.push(s2.top());
        s2.pop();
    }

    int moves = 0;

    while (!s1.empty()) {
        moves++;
        if (s2.empty() || s1.top() != s2.top()) {
            s2.push(s1.top());
            s1.pop();
        } else {
            s1.pop();
            s2.pop();
        }
    }

    if (!s1.empty() || !s2.empty())
        cout << "impossible" << endl;
    else cout << moves << endl;
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
    int t = 1;
    //    cin >> t;
    while (t--) {
        solve();
    }
    //================================================================

    return 0;
}