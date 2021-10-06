#include <bits/stdc++.h>

using namespace std;

int main(){
    const string infs = "RGB";
    int t;
    cin>>t;
    int n, k;
    while(t--){
        cin>>n>>k; 
        vector<vector<int> > dp((n+1), vector<int> (3));
        string t;
        cin>>t;
        dp[0][0] = t[0] != infs[0];
        dp[0][1] = t[0] != infs[1];
        dp[0][2] = t[0] != infs[2];
        for(int i = 1; i < n; i++){
            dp[i][0] = dp[i-1][0] + (t[i] != infs[i%3]);
            dp[i][1] = dp[i-1][1] + (t[i] != infs[(i + 1)%3]);
            dp[i][2] = dp[i-1][2] + (t[i] != infs[(i + 2)%3]);
        }
        int ans = INT_MAX;
        for(int i = 0;i < 3; i++){
            for(int j = 0;j < n; j++ ){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i = 0; i < n-k; i++){
            // cout<<dp[i + k-1][0] - dp[i][0]<<endl;
            // cout<<dp[i + k-1][1] - dp[i][1]<<endl;
            // cout<<dp[i + k-1][2] - dp[i][2]<<endl;
            ans = min(ans, (dp[i + k-1][0] - dp[i][0]));
            ans = min(ans, (dp[i + k-1][1] - dp[i][1]));
            ans = min(ans, (dp[i + k-1][2] - dp[i][2]));
        }
        cout<<ans<<endl;
    }
}