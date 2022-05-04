#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, s;
    cin >> n >> m >> s;

    vector<int> mains(m);
    vector<int> sides(s);

    for (int i = 0; i < m; i++) {
        cin >> mains[i];
    }
    for (int i = 0; i < s; i++) {
        cin >> sides[i];
    }

    sort(mains.begin(), mains.end());
    sort(sides.begin(), sides.end());

    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans = max(ans, mains[i] + sides[n - i - 1]);
    }

    cout << ans << endl;
}
