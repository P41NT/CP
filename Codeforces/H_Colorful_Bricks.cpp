#include <bits/stdc++.h>

using namespace std;

#define int long long int

vector< vector<int> > dp(2001, vector<int> (2001, -1));

int solve(int n, int m, int k){
    if(dp[n][k] != -1) return dp[n][k];
    if(k == 0) return m;
    if(n == 1) return 0;
    int answer = solve(n-1, m, k) % 998244353;
    answer +=  solve(n-1, m, k-1) * (m-1) % 998244353;
    return dp[n][k] = answer;
}

int32_t main(){
    int n, m, k;
    cin>>n>>m>>k;
    cout<<solve(n, m, k);
}