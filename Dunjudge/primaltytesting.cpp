#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

void sieve(vector<bool> &prime) {
    prime[1] = false;
    for (int i = 2; i <= 1000; i++) {
        if (prime[i] && i * i <= 1000) {
            for (int k = i * i; k <= 1000; k += i) {
                prime[k] = false;
            }
        }
    }
}

int32_t main() {
    int n;
    cin >> n;

    vector<bool> prime(1005, true);

    sieve(prime);

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int k;
    for (int i = 0; i < n; i++) {
        k = arr[i];
        if (prime[k]) {
            cout << k << " is a prime number.";
        } else {
            cout << k << " is a composite number.";
        }
        if (i < n - 1) cout << "\n";
    }
}
