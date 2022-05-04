#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define int long long int

int32_t main() {
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr[i] = {temp, i + 1};
    }
    sort(arr.begin(), arr.end());

    vector<int> solution(2);

    solution[0] = arr[arr.size() - 1].second;
    solution[1] = arr[arr.size() - 2].second;

    sort(solution.begin(), solution.end());

    cout << solution[0] << " " << solution[1] << endl;
}
