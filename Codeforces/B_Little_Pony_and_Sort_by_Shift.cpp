#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

void solve()
{
    // code goes here
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int index = -1;
    bool done = false;
    int decreasing = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            index = i;
            decreasing++;
        }
    }
    if (index == -1)
        cout << 0 << endl;
    else if (decreasing == 1 && arr[0] >= arr[n - 1])
        cout << n - index - 1;
    else
        cout << -1 << endl;
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