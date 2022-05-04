#include <bits/stdc++.h>

using namespace std;

#define int long long int

int32_t main() {
    int n, m;
    cin >> n >> m;

    if (m < n - 1) {
        cout << -1 << endl;
        return 0;
    }

    int sum = 0;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), greater<int>());

    for (int i = 1; i < n; i++) {
        sum += arr[i] + arr[0];
    }
    cout << sum << endl;
}
