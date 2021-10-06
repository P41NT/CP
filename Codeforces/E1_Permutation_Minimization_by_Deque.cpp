#include <bits/stdc++.h>

using namespace std;

#define int long long int

void solve(){

    int n;
    cin>>n;
    vector<int> v(n);
    deque<int> solution;
    for(int i = 0 ; i < n; i++){
        cin>>v[i];
    }
    solution.push_back(v[0]);
    int mini = v[0];
    for(int i = 1;i < n; i++){
        if(v[i] < mini){
            solution.push_front(v[i]);
        }
        else{
            solution.push_back(v[i]);
        }
        mini = min(mini, v[i]);
    }
    for(int i = 0; i< n; i++){
        cout<<solution[i]<<" ";
    }
    cout<<"\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
