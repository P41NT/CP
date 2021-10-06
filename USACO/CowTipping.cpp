#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

int flip(int x, int y, vector<vector<bool>> &v){
    if(v[x][y]){
        for(int i = 0; i <= x; i++){
            for(int j = 0; j <= y; j++){
                v[i][j] = !v[i][j];
            }
        }
        return 1;
    }
    return 0;
}

void solve(){
    //code goes here
    int n;
    cin>>n;
    vector<vector<bool>> v(n, vector<bool>(n));
    for(int i = 0; i < n; i++){
        char a;
        for(int j = 0; j < n; j++){
            cin>>a;
            v[i][j] = a == '1'? true : false;
        }
    }
    int ans = 0;
    for(int y = n-1; y >= 0; y--){
        for(int x = n-1; x >= 0; x--){
            ans += flip(x, y, v);
        }
    }
    cout<<ans<<endl;

}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //================================================================
    int t;
    t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    //================================================================

    return 0;
}