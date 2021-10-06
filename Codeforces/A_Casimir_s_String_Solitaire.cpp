#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        int a, b, c;
        a = b = c = 0;
        for(int i = 0; i < str.length(); i++){
            switch(str[i]){
                case 'A': a++; break;
                case 'B': b++; break;
                case 'C': c++; break;
            }
        }
        if(a + c == b){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}