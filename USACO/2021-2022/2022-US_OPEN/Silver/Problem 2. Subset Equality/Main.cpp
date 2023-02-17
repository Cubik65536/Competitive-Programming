
#include<bits/stdc++.h>
using namespace std;

using str = string;

const int MAX_N = 1e5;

str s, t;
int q;

set<char> letters;
str queries[MAX_N];

bool conflict[18][18];

void letterConflict(char c1, char c2) {
    int index1 = c1 - 'a';
    int index2 = c2 - 'a';
    if (conflict[index1][index2] || conflict[index2][index1]) {
        return;
    }

    str s1 = "";
    str s2 = "";
    for (char c: s) {
        if (c == c1 || c == c2) {
            s1 += c;
        }
    }
    for (char c: t) {
        if (c == c1 || c == c2) {
            s2 += c;
        }
    }
    if (s1 != s2) {
        conflict[index1][index2] = true;
        conflict[index2][index1] = true;
    }
}

void solve(str query) {
    if (query.size() == 1) {
        char queryChar = query[0];
        int sCount = 0;
        for (char c: s) {
            if (c == queryChar) {
                sCount++;
            }
        }
        int tCount = 0;
        for (char c: t) {
            if (c == queryChar) {
                tCount++;
            }
        }
        if (sCount == tCount) {
            cout << "Y";
        } else {
            cout << "N";
        }
        return;
    }

    for (int l = 0; l < query.length(); l++) {
        for (int r = l + 1; r < query.length(); r++) {
            if (conflict[query[l] - 'a'][query[r] - 'a'] || conflict[query[r] - 'a'][query[l] - 'a']) {
                cout << "N";
                return;
            }
        }
    }
    cout << "Y";
}

int main() {
    cin >> s >> t;
    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> queries[i];
        for (char c : queries[i]) {
            letters.insert(c);
        }
    }

    for (char c1 : letters) {
        for (char c2 : letters) {
            letterConflict(c1, c2);
        }
    }

    for (int i = 0; i < q; i++) {
        solve(queries[i]);
    }

    cout << endl;

    return 0;
}
