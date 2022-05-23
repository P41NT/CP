#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

const int m = 1000001;
vector<bool> primes(m, true);
set<int> s;

void seive()
{
    primes[0] = primes[1] = false;
    for (int i = 2; i * i <= m; i++)
    {
        if (primes[i])
        {
            for (int j = i; i * j <= m; j++)
            {
                primes[i * j] = false;
            }
        }
    }
    for (int i = 2; i <= m; i++)
    {
        if (primes[i])
        {
            s.insert(i * i);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    if (s.find(n) != s.end())
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //================================================================
    seive();
    int t;
    // t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    //================================================================

    return 0;
}