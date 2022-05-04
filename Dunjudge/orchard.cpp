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

int32_t main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n + 1, vector<int>(m + 1));
    vector<vector<int>> prefix(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    int totalnumberofbananas = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            prefix[i][j] = arr[i][j] + prefix[i - 1][j];
            totalnumberofbananas += arr[i][j];
        }
    }

    vector<int> apples(m + 1), bananas(m + 1);
    vector<int> dp(m + 1);

    int ans = totalnumberofbananas;

    for (int up = 1; up <= n; up++) {
        for (int down = up; down <= n; down++) {
            dp[0] = totalnumberofbananas;
            for (int i = 1; i <= m; i++) {
                bananas[i] = prefix[down][i] - prefix[up - 1][i];
                apples[i] = (down - up + 1) - bananas[i];
                dp[i] = min(dp[i - 1], dp[i - 1] - bananas[i] + apples[i]);
                ans = min(ans, dp[i]);
            }
            debug(up, down, bananas, apples, dp);
        }
    }

    cout << ans << endl;
}
