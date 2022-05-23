#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

void solve()
{
    // code goes here
    string s;
    cin >> s;
    int k;
    cin >> k;
    vector<int> arr(26);
    int m = 0;
    for (int i = 0; i < 26; i++)
    {
        cin >> arr[i];
        m = max(m, arr[i]);
    }
    int curr_score = 0;
    int i = 0;
    for (; i < s.size(); i++)
    {
        curr_score += (i + 1) * (arr[(s[i] - 'a')]);
    }
    for (int i = 0; i < k; i++)
    {
        curr_score += (i + s.size() + 1) * m;
    }
    cout << curr_score;
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