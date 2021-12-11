#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

void solve(){
    //code goes here
    vector<vector<int>> arr(2001, vector<int>(2001, -1));
    int curr_x = 1000;
    int curr_y = 1000;
    int t = 0;
    arr[curr_x][curr_y] = t++;
    int n;
    cin>>n;
    int ans = LONG_MAX;
    while(n--){
        char dir; int mag;
        cin>>dir>>mag;
        int dir_m = 1;
        if(dir == 'N' || dir == 'E') dir_m = -1;
        for(int i = 1; i <= mag; i++){
            if(dir == 'N' || dir == 'S') curr_y += dir_m;
            if(dir == 'E' || dir == 'W') curr_x += dir_m;
            if(arr[curr_x][curr_y] != -1) ans = min(ans, t - arr[curr_x][curr_y]);
            arr[curr_x][curr_y] = t++;
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