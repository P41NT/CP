#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"
#define forj(i, k, j) for(int i = k; i <= j; i++)

void solve(){
    //code goes here
    int n, max_height;
    cin>>n>>max_height;
    vector<int> boxes(n + 1);
    for(int i = 1; i <= n; i++)
        cin>>boxes[i];
    int opcode = 100;
    int crane_has = 0;
    int crane = 1;
    while(opcode != 0){
        cin>>opcode;
        switch(opcode){
            case 3:
                if(crane_has == 0 && boxes[crane] != 0){
                    crane_has = 1;
                    boxes[crane ]--;
                }
                break;
            case 4:
                if(crane_has == 1 && boxes[crane] != max_height){
                    crane_has = 0;
                    boxes[crane] ++;
                }
                break;
            case 2:
                crane = min(n, crane + 1);
                break;
            case 1:
                crane = max(1ll, crane - 1);
                break;
        }
    }
    for(int i = 1; i <= n;i++){
        cout<<boxes[i]<<" ";
    }
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