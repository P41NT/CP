#include <bits/stdc++.h>

using namespace std;

#define int long long int

int32_t main(){
    int n;
    cin>>n;
    vector<int> v(n);
    int m = 0;
    for(int i = 0; i < n; i++){
        cin>>v[i];
        m = max(m, v[i]);
    }
    vector<int> freq(m+1);
    for(int i = 0; i< n; i++){
        freq[v[i]]++;
    }
    vector<int> dp(m + 1);
    dp[0] = 0;
    dp[1] = freq[1];
    for(int i = 2; i <= m; i++){
        dp[i] = max(dp[i-1], i * freq[i] + dp[i-2]);
    }
    cout<<dp[m]<<endl;
}