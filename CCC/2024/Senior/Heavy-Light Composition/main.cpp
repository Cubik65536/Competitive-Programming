#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int alphabets[] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };

    int T, N;
    cin >> T >> N;

    string str;
    for (int i = 0; i < T; i++) {
        cin >> str;

        char curr;
        char prev;

        bool result = true;

        alphabets[str[0] - 97]++;
        for (int j = 1; j < N; j++) {
            prev = str[j - 1];
            curr = str[j];
            alphabets[curr - 97]++;
            if (alphabets[prev - 97] > 1 && alphabets[curr - 97] > 1) {
                result = false;
                break;
            }
        }

        for (int j = 1; j < N && result; j++) {
            prev = str[j - 1];
            curr = str[j];
            if ((alphabets[prev - 97] > 1 && alphabets[curr - 97] > 1)
            || (alphabets[prev - 97] == 1 && alphabets[curr - 97] == 1)) {
                result = false;
                break;
            }
        }

        if (result) {
            cout << "T" << endl;
        } else {
            cout << "F" << endl;
        }

        for (int c = 0; c < 26; c++) {
            alphabets[c] = 0;
        }
    }
    
    return 0;
}
