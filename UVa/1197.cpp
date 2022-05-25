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

vector<int> lnk;
vector<int> sz;

int find(int x) {
    if (lnk[x] == x) return x;
    return lnk[x] = find(lnk[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return;

    if (sz[y] > sz[x]) swap(x, y);

    lnk[y] = x;
    sz[x] += sz[y];
}

int sze(int x) {
    x = find(x);
    return sz[x];
}

void solve(int n, int m) {
    lnk.resize(n);
    sz.resize(n);

    for (int i = 0; i < n; i++) {
        lnk[i] = i;
    }
    fill(sz.begin(), sz.end(), 1);

    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;

        int init;
        cin >> init;

        debug(lnk, sz);

        for (int j = 0; j < k - 1; j++) {
            int x;
            cin >> x;
            unite(init, x);
        }
    }

    cout << sze(0) << endl;
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
    int t, s;
    while (cin >> t >> s) {
        if (t == 0 && s == 0) break;
        solve(t, s);
    }
    //================================================================

    return 0;
}
