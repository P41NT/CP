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
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> gaps;
    int ans = 0;
    int currentgap = 0;
    bool canadd = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] && canadd) {
            ans++;
            if (currentgap == 0) continue;
            gaps.push_back(currentgap);
            currentgap = 0;
        } else if (arr[i] && !canadd) {
            ans++;
            canadd = true;
        } else if (canadd)
            currentgap++;
    }

    sort(gaps.begin(), gaps.end());

    for (int i = 0; i < max(0ll, (int)gaps.size() - m + 1); i++) {
        ans += gaps[i];
    }
    cout << ans << endl;
}
