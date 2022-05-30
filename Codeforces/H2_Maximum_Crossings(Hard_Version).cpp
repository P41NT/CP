//
// Created by p41nt on 28/5/22.
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

vector<vector<int>> segtree;
vector<int> arr;

void merge(vector<int> &a, vector<int> &b, vector<int> &res) {
    int i = 0;
    int j = 0;

    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j])
            res.push_back(a[i++]);
        else
            res.push_back(b[j++]);
    }

    while (i < a.size()) {
        res.push_back(a[i++]);
    }
    while (j < b.size()) {
        res.push_back(b[j++]);
    }
}

void build(int index, int left, int right) {
    if (left == right) {
        segtree[index] = {arr[left]};
        return;
    }
    int mid = (left + right) / 2;
    build(index * 2, left, mid);
    build(index * 2 + 1, mid + 1, right);

    merge(segtree[index * 2], segtree[index * 2 + 1], segtree[index]);
}

int query(int index, int left, int right, int ql, int qr, int search) {
    if (left >= ql && right <= qr)
        return segtree[index].end() - lower_bound(segtree[index].begin(),
                                                  segtree[index].end(), search);
    if (qr < left || ql > right) return 0;

    int mid = (left + right) / 2;
    return query(index * 2, left, mid, ql, qr, search) +
           query(index * 2 + 1, mid + 1, right, ql, qr, search);
}

void solve() {
    int n;
    cin >> n;

    segtree.resize(4 * n);
    arr.resize(n);

    fill(segtree.begin(), segtree.end(), vector<int>());

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    build(1, 0, n - 1);

    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans += query(1, 0, n - 1, 0, i - 1, arr[i]);
        debug(i, ans);
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
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    //================================================================

    return 0;
}
