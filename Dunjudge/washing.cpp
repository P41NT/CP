#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, h;
    cin >> n >> h;

    vector<string> arr(h);
    for (int i = 0; i < h; i++) {
        cin >> arr[i];
    }

    int maxc = 0;
    int currc = 0;

    for (int i = 0; i < h; i++) {
        if (arr[i] == "USE")
            currc++;
        else
            currc = 0;

        maxc = max(maxc, currc);
    }
    cout << (maxc > n ? "DIRTY" : "CLEAN") << endl;
}
