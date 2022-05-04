#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define int long long int

int32_t main() {
    int n, l, t;
    cin >> n >> l >> t;

    vector<int> arr(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    arr[n] = l - 1;
    sort(arr.begin(), arr.end());
    int curr = t;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i] - arr[i - 1] > t) {
            cout << -1 << endl;
            return 0;
        }
        if (arr[i] - arr[i - 1] > curr) {
            curr = t - (arr[i] - arr[i - 1]);
            ans++;
        } else {
            curr -= arr[i] - arr[i - 1];
        }
    }

    cout << ans << endl;
}
