#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, l;
    cin >> n >> l;
    string st;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> st;
        for (auto s : st) {
            arr[i] += tolower(s) - 'a' + 1;
        }
    }

    sort(arr.begin(), arr.end(), greater<int>());
    int ans = 0;
    for (int i = 0; i < l; i++) {
        ans += arr[i];
    }

    cout << ans << endl;
}
