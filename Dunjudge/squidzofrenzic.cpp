#include <bits/stdc++.h>

using namespace std;

#define int long long int

int32_t main() {
    int n, k;
    cin >> n >> k;

    int low = 0, high = 0;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        high += arr[i];
    }

    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        int k_ = 1;
        int curr = 0;
        for (int i = 0; i < n; i++) {
            if (curr + arr[i] > mid) {
                curr = arr[i];
                k_++;
            } else {
                curr += arr[i];
            }
        }
        if (k_ <= k) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << mid << endl;
}
