#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    int ans = 0;
    for (int i = 0, curr = 1; i < n; i++) {
        if (arr[i] >= curr) {
            ans++;
            curr++;
        }
    }

    cout << ans << endl;
}
