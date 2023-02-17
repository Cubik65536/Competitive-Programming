#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    string letters = "";
    string turns = "";

    bool isNumber = false;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == '+') {
            cout << letters + " tighten ";
            letters = "";
        } else if (c == '-') {
            cout << letters + " loosen ";
            letters = "";
        } else if (c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '0') {
            isNumber = true;
            turns += c;
            if (i == s.length() - 1) {
                cout << turns << endl;
            }
        } else {
            if (isNumber) {
                cout << turns << endl;
                isNumber = false;
                turns = "";
            }
            letters += c;
        }
    }

    return 0;
}
