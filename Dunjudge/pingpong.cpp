#include <iostream>

using namespace std;

string winner(string S) {
    int wins = 0;
    int curr = 0;
    int potato = 0, rar = 0;
    while (true) {
        if (S[curr] == 'R')
            rar++;
        else if (S[curr] == 'P')
            potato++;
        if (potato >= 11 && potato - rar >= 2) {
            wins++;
            potato = 0, rar = 0;
        } else if (rar >= 11 && rar - potato >= 2) {
            wins--;
            potato = 0, rar = 0;
        }
        if (++curr == S.size()) break;
    }

    return (wins > 0) ? "Potato" : "Rar";
}

int main() {
    string s;
    cin >> s;
    cout << winner(s) << endl;
}
