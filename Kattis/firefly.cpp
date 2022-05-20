//
// Created by p41nt on 16/5/22.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, h;
    cin >> n >> h;

    vector<int> down(n / 2), up(n / 2);

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            cin >> down[i / 2];
        else
            cin >> up[i / 2];
    }

    sort(down.begin(), down.end());
    sort(up.begin(), up.end());

    map<int, int> ans;

    for (int i = 1; i <= h; i++) {
        int lowers = (lower_bound(down.begin(), down.end(), i) - down.begin());
        int highers =
            (lower_bound(up.begin(), up.end(), h - i + 1) - up.begin());
        ans[(n / 2 - lowers) + (n / 2 - highers)]++;
    }

    cout << ans.begin()->first << " " << ans.begin()->second << endl;
}
