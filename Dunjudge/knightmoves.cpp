#include <iostream>
#include <queue>
#include <vector>

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

vector<pair<int, int>> directions = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
                                     {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

int n;
pair<int, int> initial, final;

vector<vector<bool>> visited(51, vector<bool>(51, false));
vector<vector<int>> dist(51, vector<int>(51));

int32_t main() {
    cin >> n;

    cin >> initial.first >> initial.second;
    cin >> final.first >> final.second;

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;

        visited[a][b] = true;
    }

    queue<pair<int, int>> bfs;
    bfs.push(initial);
    dist[initial.first][initial.second] = 0;

    while (!bfs.empty()) {
        auto curr = bfs.front();
        bfs.pop();
        if (visited[curr.first][curr.second]) continue;

        visited[curr.first][curr.second] = true;

        for (int i = 0; i < 8; i++) {
            pair<int, int> next = {curr.first + directions[i].first,
                                   curr.second + directions[i].second};

            if (next.first >= 1 && next.first <= n && next.second >= 1 &&
                next.second <= n && !visited[next.first][next.second]) {
                dist[next.first][next.second] =
                    1 + dist[curr.first][curr.second];
                bfs.push(next);
            }
        }
    }

    cout << dist[final.first][final.second] << endl;
}
