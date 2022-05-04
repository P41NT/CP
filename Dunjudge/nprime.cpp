#include <iostream>
#include <vector>

using namespace std;

void sieve(vector<int> &primes) {
    vector<bool> isPrime(1000005, true);
    for (int i = 2; i * i < isPrime.size(); i++) {
        if (isPrime[i]) {
            for (int k = i * i; k < isPrime.size(); k += i) isPrime[k] = false;
        }
    }

    for (int i = 2; i < isPrime.size(); i++) {
        if (isPrime[i]) primes.push_back(i);
    }
}

int32_t main() {
    vector<int> primes;

    sieve(primes);

    int n;
    cin >> n;

    cout << primes[n - 1] << endl;
}
