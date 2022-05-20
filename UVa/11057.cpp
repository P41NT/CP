//
// Created by p41nt on 16/5/22.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int k;
        cin >> k;
        set<int> st;

        vector<pair<int, pair<int, int>>> ans;

        for (int i = 0; i < n; i++) {
            if (st.find(arr[i]) != st.end()) {
                ans.push_back({abs(arr[i] - k + arr[i]), {arr[i], k - arr[i]}});
            }
            st.insert(k - arr[i]);
        }

        sort(ans.begin(), ans.end());

        int tempa = min(ans[0].second.second, ans[0].second.first);
        int tempb = max(ans[0].second.second, ans[0].second.first);

        cout << "Peter should buy books whose prices are " << tempa << " and "
             << tempb << ".\n\n";
    }
}
