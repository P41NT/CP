//
// Created by p41nt on 30/5/22.
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

vector<int> palindromes;

bool palindrome(int i) {
    string s = to_string(i);
    reverse(s.begin(), s.end());

    return i == stoll(s);
}

vector<vector<int>> dp(4 * 1e4 + 5, vector<int>(503, -1));

const int MOD = (int)1e9 + 7;

int recur(int n, int m) {
    if (n == 0) return 1;
    if (m == 0) return 0;
    if (n < 0) return 0;

    //    debug(n, m);

    if (dp[n][m] != -1) return dp[n][m];
    //    debug(n, m);
    if (palindromes[m] <= n)
        return dp[n][m] =
                   (recur(n, m - 1) + recur(n - palindromes[m], m)) % MOD;
    return dp[n][m] = recur(n, m - 1) % MOD;
}

void precalc() {
    palindromes.push_back(0);
    for (int i = 1; i <= 2 * 40004; i++) {
        if (palindrome(i)) palindromes.push_back(i);
    }
    recur(4 * 1e4, 502);
}

void solve() {
    int n;
    cin >> n;
    cout << recur(n, 502) << endl;
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
    precalc();
    while (t--) {
        solve();
    }
    //================================================================

    return 0;
}
