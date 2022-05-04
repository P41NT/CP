#include <bits/stdc++.h>

#include <climits>

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
    vector<vector<pair<int, int>>> G(n);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }

    int k;
    cin >> k;

    vector<int> dist1(n, LONG_MAX);
    vector<int> dist2(n, LONG_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq1;

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq2;

    dist1[0] = 0;
    pq1.push({0, 0});

    dist2[n - 1] = 0;
    pq2.push({0, n - 1});

    while (!pq1.empty()) {
        auto curr = pq1.top();
        pq1.pop();
        if (curr.first != dist1[curr.second]) continue;
        for (auto s : G[curr.second]) {
            if (curr.first + s.second < dist1[s.first]) {
                dist1[s.first] = curr.first + s.second;
                pq1.push({dist1[s.first], s.first});
            }
        }
    }

    while (!pq2.empty()) {
        auto curr = pq2.top();
        pq2.pop();
        if (curr.first != dist2[curr.second]) continue;
        for (auto s : G[curr.second]) {
            if (curr.first + s.second < dist2[s.first]) {
                dist2[s.first] = curr.first + s.second;
                pq2.push({dist2[s.first], s.first});
            }
        }
    }

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;

        int ans = LONG_LONG_MIN;

        if (dist1[x] < LONG_MAX && dist2[y] < LONG_MAX)
            ans = dist1[n - 1] - 1 - dist1[x] - dist2[y];
        if (dist2[x] < LONG_MAX && dist1[y] < LONG_MAX)
            ans = max(ans, dist1[n - 1] - 1 - dist2[x] - dist1[y]);

        // int ans = max(dist1[n - 1] - 1 - dist1[x] - dist2[y],
        //               dist1[n - 1] - 1 - dist1[y] - dist2[x]);

        if (ans < 0)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
}

