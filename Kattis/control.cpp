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

vector<int> lnk(500005);
vector<int> sz(500005);

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

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i <= 500000; i++) {
        lnk[i] = i;
        sz[i] = 1;
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        vector<int> temp(k);
        set<int> s;

        for (int j = 0; j < k; j++) {
            cin >> temp[j];
            s.insert(find(temp[j]));
        }

        int sum = 0;
        for (auto h : s) sum += sz[h];

        if (sum == k) {
            ans++;
            for (int j = 1; j < k; j++) {
                unite(temp[0], temp[j]);
            }
        }
    }
    cout << ans << endl;
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
