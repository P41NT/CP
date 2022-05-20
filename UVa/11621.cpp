//
// Created by p41nt on 16/5/22.
//
#include <bits/stdc++.h>

using namespace std;

#define int long long int

int32_t main() {
    set<int> numbers;

    for (int i = 0; i <= 31; i++)
        for (int j = 0; j <= 31; j++) {
            int p = pow(2, i) * pow(3, j);
            if (p <= pow(2, 31)) numbers.insert(p);
        }

    int query;
    while (cin >> query) {
        if (query == 0) return 0;
        cout << *(numbers.lower_bound(query)) << '\n';
    }
}