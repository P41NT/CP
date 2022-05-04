#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int32_t main() {
    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end(), cmp);

    // for (int i = 0; i < n; i++) {
    //     cout << arr[i].first << " " << arr[i].second << endl;
    // }

    int ans = 1;
    int last = arr[0].second;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i].first >= last) {
            last = arr[i].second;
            ans++;
        }
    }
    cout << ans << endl;
}
