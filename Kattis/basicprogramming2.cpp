//
// Created by p41nt on 24/5/22.
//
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

void solve() {
    // code goes here
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    if (m == 1) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (binary_search(arr.begin(), arr.end(), 7777 - arr[i])) {
                found = true;
                break;
            }
        }
        if (found)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    } else if (m == 2) {
        bool is_unique = true;
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] == arr[i]) is_unique = false;
        }

        if (is_unique)
            cout << "Unique" << endl;
        else
            cout << "Contains duplicate" << endl;
    } else if (m == 3) {
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] == arr[i])
                count++;
            else
                count = 1;
            if (count > n / 2) {
                cout << arr[i] << endl;
                return;
            }
        }

        cout << -1 << endl;
    } else if (m == 4) {
        if (n % 2 == 0)
            cout << arr[(n / 2) - 1] << " " << arr[n / 2] << endl;
        else
            cout << arr[(n + 1) / 2 - 1] << endl;
    } else if (m == 5) {
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (arr[i] > 999) break;
            if (arr[i] > 100) ans.push_back(arr[i]);
        }
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i];
            if (i == ans.size() - 1)
                cout << endl;
            else
                cout << " ";
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("../Current/input.txt", "r", stdin);
    freopen("../Current/output.txt", "w", stdout);
#endif

    //================================================================
    int t;
    t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }
    //================================================================

    return 0;
}
