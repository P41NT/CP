#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

void solve()
{
    //code goes here
    string s;
    cin >> s;
    int n = s.size() - 1;
    int ind = -1;
    for (int i = 0; i <= n; i++)
    {
        if ((s[i] - '0') % 2 == 0)
        {
            ind = i;
            if (s[n] > s[i])
                break;
        }
    }
    if (ind == -1)
        cout << "-1" << endl;
    else
    {
        swap(s[n], s[ind]);
        cout << s << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //================================================================
    int t;
    t = 1;
    //cin>>t;
    while (t--)
    {
        solve();
    }
    //================================================================

    return 0;
}