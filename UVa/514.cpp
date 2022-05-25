//
// Created by p41nt on 25/5/22.
//
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

void solve(int n) {
    // code goes here

    while (true) {
        vector<int> arr(n);
        cin >> arr[0];
        if (arr[0] == 0) {
            cout << endl;
            break;
        }
        for (int i = 1; i < n; i++) cin >> arr[i];

        stack<int> st;
        int currentCart = 1;
        int currentTarget = 0;
        while (currentCart <= n) {
            st.push(currentCart++);
            while (!st.empty() && st.top() == arr[currentTarget]) {
                st.pop();
                currentTarget++;

                if (currentTarget >= n) break;
            }
        }

        if (st.empty())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
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
    //    t = 1;
    while (cin >> t) {
        if (t == 0) break;
        solve(t);
    }
    //================================================================

    return 0;
}
