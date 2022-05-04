#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <vector>

#define int long long
#define endl "\n"

using namespace std;

map<char, int> profit = {{'o', 100}, {'e', 10},  {'g', 1},   {'a', 0},
                         {'b', -1},  {'i', -10}, {'u', -100}};

int32_t main() {
    while (true) {
        vector<int> arr;
        char c;
        while (cin >> c) {
            if (c == ' ')
                continue;
            if (c == ',' || c == '.')
                break;
            arr.push_back(profit[c]);
        }
        int n = arr.size();
        vector<int> dp(n);
        dp[0] = max(0ll, arr[0]);
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        }

        cout << *max_element(dp.begin(), dp.end()) << endl;

        if (c == '.')
            return 0;

        arr.clear();
    }
}
