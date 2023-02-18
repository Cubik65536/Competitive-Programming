#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    int result = 0;

    while (N--) {
        string p;
        cin >> p;

        if (p[0] == 'P') {
            result += 1500;
        } else if (p[0] == 'M') {
            result += 6000;
        } else if (p[0] == 'S') {
            result += 15500;
        } else if (p[0] == 'C') {
            result += 40000;
        } else if (p[0] == 'T') {
            result += 75000;
        } else if (p[0] == 'H') {
            result += 125000;
        }
    }

    cout << result << endl;
    
    return 0;
}
