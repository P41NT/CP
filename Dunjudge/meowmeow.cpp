#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    string temp;

    int male = 0, female = 0;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp == "MEW")
            male++;
        else if (temp == "MEOW")
            female++;
    }

    if (male == 0)
        cout << "OMG MEEEAHHHH!!!! " << endl;
    else
        cout << (female / male) << endl;
}
