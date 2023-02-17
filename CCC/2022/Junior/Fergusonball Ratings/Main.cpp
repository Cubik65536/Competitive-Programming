#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    int result = 0;

    for (int i = 0; i < N; i++) {
        int points, fouls;
        cin >> points >> fouls;
        int point = 5 * points - 3 * fouls;
        if (point > 40) result++;
    }

    cout << result;
    if (result == N) cout << "+";
    cout << endl;

    return 0;
}
