#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int P, C;
    cin >> P >> C;

    int result = 0;

    result += P * 50;
    result -= C * 10;

    if (P > C) {
        result += 500;
    }

    cout << result << endl;
    
    return 0;
}
