#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int S, M, L;
    cin >> S >> M >> L;

    if ((M + (2 * S) + (3 * L)) < 10) {
        cout << "sad" << endl;
    } else {
        cout << "happy" << endl;
    }
    
    return 0;
}
