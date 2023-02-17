#include<bits/stdc++.h>

using namespace std;

int main() {
    int B;
    cin >> B;

    int P = 5 * B - 400;
    
    cout << P << endl;

    if (P < 100) {
        cout << "1" << endl;
    } else if (P > 100) {
        cout << "-1" << endl;
    } else {
        cout << "0" << endl;
    }

    return 0;
}
