//
// Created by p41nt on 25/5/22.
//

#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

void solve() {
    // code goes here
    int n;
    cin >> n;

    stack<int> st;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (st.empty())
            st.push(x);
        else {
            if ((st.top() + x) % 2 == 0)
                st.pop();
            else
                st.push(x);
        }
    }

    cout << st.size() << endl;
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
