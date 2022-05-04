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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r, c, k, m;
    cin >> r >> c >> k >> m;

    // vector<vector<char>> arr(r + 1, vector<char>(c + 1));

    vector<vector<int>> sprinklers(r + 1, vector<int>(c + 1));
    vector<pair<int, int>> mushrooms;

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            // cin >> arr[i][j];
            char temp;
            cin >> temp;
            sprinklers[i][j] = sprinklers[i - 1][j] + sprinklers[i][j - 1] -
                               sprinklers[i - 1][j - 1];
            if (temp == 'M')
                mushrooms.push_back({i, j});
            else if (temp == 'S')
                sprinklers[i][j]++;
        }
    }

    // debug(sprinklers);

    int ans = 0;

    for (auto mushroom : mushrooms) {
        int x = mushroom.first, y = mushroom.second;
        int yr = min(y + k, c), yl = max(0, y - k - 1);
        int xd = min(x + k, r), xu = max(0, x - k - 1);

        // debug(yr, yl, xd, xu);

        int sprinkle = sprinklers[xd][yr] - sprinklers[xd][yl] -
                       sprinklers[xu][yr] + sprinklers[xu][yl];

        if (sprinkle >= m) ans++;
    }
    cout << ans << endl;
}
