#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define int long long int

int n, a, b;

struct point {
    int index, x, y;
};

int dist(point k) { return abs(k.x - a) + abs(k.y - b); }

inline bool comp(point a, point b) {
    int dist1, dist2;
    dist1 = dist(a), dist2 = dist(b);

    if (dist1 == dist2) return a.index < b.index;
    return dist1 < dist2;
}

int32_t main() {
    cin >> n >> a >> b;

    vector<point> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y;
        arr[i].index = i + 1;
    }

    sort(arr.begin(), arr.end(), comp);

    for (point a : arr) {
        cout << a.index << " ";
    }
    cout << endl;
}
