#include <bits/stdc++.h>

using namespace std;

#define int long long int

bool possible = true;

struct Rectangle {
    int x1, x2, y1, y2;
    Rectangle(int x1, int x2, int y1, int y2) {
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;
    }

    int area() {
        if (x1 > x2 || y1 > y2) return 0;
        return (x2 - x1) * (y2 - y1);
    }

    void print() { cerr << x1 << " " << x2 << " " << y1 << " " << y2 << endl; }
};

void intersect(Rectangle &ans, Rectangle &curr) {
    ans.x1 = max(ans.x1, curr.x1);
    ans.x2 = min(ans.x2, curr.x2);
    ans.y1 = max(ans.y1, curr.y1);
    ans.y2 = min(ans.y2, curr.y2);
}

int32_t main() {
    int n;
    cin >> n;

    Rectangle ans(0, 10000, 0, 10000);
    Rectangle curr(0, 10000, 0, 10000);

    for (int i = 0; i < n; i++) {
        cin >> curr.x1 >> curr.x2 >> curr.y1 >> curr.y2;

        intersect(ans, curr);

        // ans.print();
    }

    cout << ans.area() << endl;
}
