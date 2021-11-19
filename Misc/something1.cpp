#include <bits/stdc++.h>

using namespace std;

string convert(int n){
    string ans = "";
    while(n > 0){
        ans = (char)(n%9 + '0') + ans;
        n /= 9;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cout<<i<<" "<<convert(i)<<endl;
    }
}