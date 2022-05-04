#include <bits/stdc++.h>

using namespace std;

vector<int> arr;
vector<int> fen;
int n;

void update(int i, int y) {
    for (; i < (int)fen.size(); i += (i & -(i))) {
        fen[i] += y;
    }
}

int sum(int i) {
    int s = 0;
    while (i > 0) {
        s += fen[i];
        i -= (i & (-i));
    }
    return s;
}

int rangesum(int l, int r) { return sum(r) - sum(l - 1); }

int main() {
    cin >> n;
    arr.resize(n + 1);
    fen.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        update(i, temp);
    }

    int k;
    cin >> k;
    while (k--) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 0) {
            cout << rangesum(b + 1, c + 1) << endl;
        } else {
            int d;
            cin >> d;
            for (int i = b; i <= c; i++) update(i, d);
        }
    }
}
