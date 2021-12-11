#include <bits/stdc++.h>

using namespace std;

const int[] choices = {-1, 0, 1};

int ans(int n, int a){
    if(n == 0) return 1;
    if(a < 0) return 0;
    int ans = 1;
    for(int x : choices){
        ans += ans(n - 1, a + x);
    }
    return ans;
}

int g(int n){
    vector<vector<int>> dp(n * 2, vector<int>(n));
    for(int i = 0 ; i < n + 10; i++){
        dp[i][0] = 1;
    }
    for(int j = 1; j < n; j++){
        for(int i = 0; i < n * 2 - 1; i++){
            if(i != 0) dp[i][j] += dp[i - 1][j - 1];
            dp[i][j] += dp[i + 1][j - 1];
            dp[i][j] += dp[i][j - 1];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n-2][n - 1];
}

int main(){
    int n;
    cin>>n;
    cout<<g(n)<<endl;
    cout<<ans(n,1);
}