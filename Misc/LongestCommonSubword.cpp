#include <bits/stdc++.h>

using namespace std;

int main(){
    string a, b;
    cin>>a>>b; 
    int n = a.size(); int m = b.size();
    vector<vector<int>> dp(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i] == b[0]){
                dp[i][0] = 1;
            }
            if(a[0] == b[i]){
                dp[0][i] = 1;
            }
            if(i && j && a[i] == b[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ans = max(ans, dp[i][j]);
        }
    }
    cout<<ans<<endl;
}