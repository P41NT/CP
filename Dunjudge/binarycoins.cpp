#include <bitset>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

#define int long long int

int32_t main() {
    int n;
    cin >> n;

    bitset<64> bits(n);

    cout << bits.count() << endl;
}
