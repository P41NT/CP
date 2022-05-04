#include <cctype>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<char, string> mp = {
    {'0', "zero"}, {'1', "one"}, {'2', "two"},   {'3', "three"}, {'4', "four"},
    {'5', "five"}, {'6', "six"}, {'7', "seven"}, {'8', "eight"}, {'9', "nine"},
};

int main() {
    int n;
    cin >> n;

    vector<string> sol(n);
    for (int i = 0; i < n; i++) {
        string k;
        cin >> k;
        string ans = "";

        for (auto s : k) {
            ans += mp[s];
            ans += " ";
        }
        ans.pop_back();
        ans[0] = toupper(ans[0]);
        cout << ans << endl;
    }
}
