#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

int main() {
    int n;
    cin >> n;

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count = 0;
    int total = 0;

    for (int i = 0; i < n; i++) {
        total += arr[i].size();

        for (auto c : arr[i]) {
            if (c == 'c' || c == 'C') count++;
        }
    }

    cout << (count * 100 / total) << "%" << endl;
}
