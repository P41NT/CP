//
// Created by p41nt on 10/5/22.
//

#include <bits/stdc++.h>

using namespace std;

#define int long long int

int32_t main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    vector<int> prefix(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    prefix[0] = arr[0];

    for (int i = 1; i < n; i++) prefix[i] = prefix[i - 1] + arr[i];
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
        if (2 * prefix[i] == prefix[n - 1]) ans++;
    cout << ans << endl;
}
