#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> prefix(n);

    prefix[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    int m;
    cin >> m;
    while (m--) {
        int k;
        cin >> k;

        cout << (lower_bound(prefix.begin(), prefix.end(), k) -
                 prefix.begin()) +
                    1
             << endl;
    }
}
