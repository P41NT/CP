#include <iostream>
#include <map>

using namespace std;

#define int long long int
#define endl "\n"

int32_t main() {
    int n, m;
    cin >> n >> m;
    map<int, int> mp;

    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        mp[temp]++;
    }
    int ans = 0;
    for (auto s : mp) {
        if (s.second >= m) continue;
        ans = max(ans, s.second);
    }

    cout << ans << endl;
}
