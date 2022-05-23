#include <bits/stdc++.h>

using namespace std;

#define int long long int

int32_t main(){
    int n,k; cin>>n>>k;
    vector <int> leapshit(n);
    for(int i =0;i<n;i++){
        cin>>leapshit[i];
    }
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for(int i=1;i<n;i++){
        for(int j = 1;j<=k;j++){
            if(i - j >= 0)
                dp[i] = min(dp[i], dp[i-j]+abs(leapshit[i]-leapshit[i-j]));
        }
    }
    cout<<dp[n-1]<<endl;
}
