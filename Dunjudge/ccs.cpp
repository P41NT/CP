#include <iostream>
#include <vector>

using namespace std;
#define int long long int

int32_t main() {
    int n, m;
    cin >> n >> m;

    bool arr[n];

    fill(arr, arr + n, true);

    for (int k = 0; k < m; k++) {
        string command;
        cin >> command;
        if (command == "TRANSMIT") {
            int a, b;
            cin >> a >> b;
            a--, b--;
            bool possible = true;
            for (int i = a; i < b; i++) {
                possible = possible & arr[i];
            }

            cout << (possible ? "YES" : "NO") << endl;
        }

        else if (command == "SLEEP") {
            int t;
            cin >> t;
            arr[t - 1] = 0;
        } else if (command == "WAKE") {
            int t;
            cin >> t;
            arr[t - 1] = 1;
        }
    }
}
