#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n";

void solve(){
    //code goes here
    int n;
    cin>>n;
    map<string, int> se;
    for(int i = 0; i< n; i++) {
        string temp; int temp1;
        cin>>temp>>temp1;
        se[temp] += temp1;
    }
    vector<pair<int, string>> se2;
    for(auto s: se){
        se2.push_back({s.second, s.first});
    }
    sort(se2.begin(), se2.end());
    int i = 0;
    if(se2.size() == 7){
        for(; i < se2.size(); i++){
            if(se2[i].first != se2[0].first) break;
        }
    }
    if(i < se2.size() && (i+1 == se2.size() || se2[i].first != se2[0].first)){
        cout<<se2[i].second;
    }
    else{
        cout<<"TIE"<<endl;
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