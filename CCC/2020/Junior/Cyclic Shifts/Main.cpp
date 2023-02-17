#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string T, S;
    cin >> T >> S;

    for (int i = 0; i < T.length() - S.length() + 1; i++) {
        bool same = true;
        for (int j = 0; j < S.length(); j++) {
            for (int k = 0; k < S.length(); k++) {
                same = true;
                if (T[i + k] != S[(j + k) % S.length()]) {
                    same = false;
                    break;
                }
            }
            if (same) {
                cout << "yes" << endl;
                return 0;
            }
        }
    }
    
    cout << "no" << endl;

    return 0;
}
