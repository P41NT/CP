#include <iostream>

using namespace std;

#define int long long

int32_t main() {
    int n, m;
    cin >> n >> m;
    m++;

    int equal = (n / m);

    cout << equal << " " << equal + (n % m) << endl;
}
