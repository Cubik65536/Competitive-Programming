#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    int H[N];

    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    int diff = N/2;

    int result = 0;
    for (int i = 0; i < N / 2 + 1; i++) {
        if (H[i] == H[i + diff]) {
            result += 2;
        }
    }

    cout << result << endl;
    
    return 0;
}
