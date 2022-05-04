#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

#define int long long int

void merge(vector<int> &arr, int start, int mid, int end) {
    vector<int> temp;

    int i = start, j = mid + 1;
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= end) temp.push_back(arr[j++]);

    for (int i = 0; i < temp.size(); i++) {
        arr[start + i] = temp[i];
    }
}

void sort(vector<int> &arr, int start, int end) {
    if (start == end) return;

    int mid = (start + end) / 2;
    sort(arr, start, mid);
    sort(arr, mid + 1, end);

    merge(arr, start, mid, end);
}

int32_t main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
}
