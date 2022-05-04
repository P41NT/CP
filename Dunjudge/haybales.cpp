#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    sum /= n;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans += max(sum - arr[i], 0);
    }
    cout << ans << endl;
}
