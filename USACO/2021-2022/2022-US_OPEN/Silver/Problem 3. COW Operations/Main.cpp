#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5;

string s;
int cCount[MAX_N];
int oCount[MAX_N];
int wCount[MAX_N];
int cPast[MAX_N];
int oPast[MAX_N];
int wPast[MAX_N];

void solve (int l, int r) {
    if (l == r) {
        if (s[l] == 'C') {
            cout << "Y";
        } else {
            cout << "N";
        }
        return;
    }
    int c = cCount[r] - cPast[l];
    int o = oCount[r] - oPast[l];
    int w = wCount[r] - wPast[l];
    if (c % 2 == 1) {
        if (o % 2 == 0 && w % 2 == 0) {
            cout << "Y";
        } else {
            cout << "N";
        }
    } else {
        if (o % 2 == 1 && w % 2 == 1) {
            cout << "Y";
        } else {
            cout << "N";
        }
    }
}

int main() {
    cin >> s;

    int c = 0, o = 0, w = 0;
    for (int i = 0; i < s.length(); i++) {
        cPast[i] = c;
        oPast[i] = o;
        wPast[i] = w;
        if (s[i] == 'C') {
            c++;
        } else if (s[i] == 'O') {
            o++;
        } else {
            w++;
        }
        cCount[i] = c;
        oCount[i] = o;
        wCount[i] = w;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        solve(l, r);
    }

    cout << endl;

    return 0;
}
