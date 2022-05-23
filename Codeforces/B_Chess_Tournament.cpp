#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"
#define vector2d(x, y, r) vector<vector<int>>(x, vector<int>(y, r));
#define vector3d(x, y, z, r) vector<vector<vector<int>>>(x, vector<vector<int>>(y, vector<int>(z, r)))
#define forj(i, j) for(int i = 0; i < j; i++) 
#define ford(i, j) for(int i = j; i >= 0; i--)
#define loop(i, l, j, h) for(int i = l; i <= j; h)

void solve(){
    //code goes here
    int n;
    cin>>n;
    vector<int> v(n);
    vector<int> second_type;
    vector<vector<char>> ans(n, vector<char>(n, '='));
    int second_type_count = 0;
    forj(i, n){
        char temp;
        cin>>temp;
        switch(temp){
            case '1':
                v[i] = 1;
                break;
            case '2': 
                v[i] = 2;
                second_type.push_back(i);
                second_type_count++;
                break;
        }
    }
    if(second_type_count <= 2 && second_type_count > 0){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        for(int i = 0; i < second_type_count; i++){
            int x = second_type[i]; int y = second_type[(i+1)%second_type_count];
            ans[x][y] = '+';
            ans[y][x] = '-';
        }
        for(int i = 0 ; i < n;i++){
            ans[i][i] = 'X';
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout<<ans[i][j];
            }
            cout<<endl;
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //================================================================
    int t;
    // t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    //================================================================

    return 0;
}