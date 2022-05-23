#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

void solve()
{
    // code goes here
    int r, x1, y1, x2, y2;
    cin >> r >> x1 >> y1 >> x2 >> y2;
    double distance = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2)) / (double)2;
    // cout << distance << endl;
    double ans = ceil(distance / double(r));
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //================================================================
    int t;
    t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
    //================================================================

    return 0;
}