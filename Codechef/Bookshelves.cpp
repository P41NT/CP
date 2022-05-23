#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

int n, k;

int sol(vector<int> &a, vector<int> &b)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int start = 0, end = n - 1, m = 0;
    while (start < n && end >= 0 && m < k)
    {
        if (a[start] > b[end])
            break;
        swap(a[start], b[end]);
        start++;
        end--;
        m++;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a[n - 1] + b[n - 1];
}

void solve()
{
    // code goes here
    cin >> n >> k;
    vector<int> a(n), b(n);
    vector<int> a1(n), b1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a1[i] = a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        b1[i] = b[i];
    }
    cout << min(sol(a, b), sol(b1, a1));
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