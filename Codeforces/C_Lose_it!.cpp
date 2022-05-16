//
// Created by p41nt on 10/5/22.
//
#include <bits/stdc++.h>

using namespace std;

map<int, int> convert = {
    {4, 1}, {8, 2}, {15, 3}, {16, 4}, {23, 5}, {42, 6},
};

int main() {
    int n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr[i] = convert[temp];
    }
}