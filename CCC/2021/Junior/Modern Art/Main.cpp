#include<bits/stdc++.h>

using namespace std;

using vi = vector<int>;

int main() {
    int M, N, K;
    cin >> M >> N >> K;

    vi row(M);
    vi col(N);

    while (K--) {
        char c;
        cin >> c;
        int index;
        cin >> index;
        index--;

        if (c == 'R') {
            row[index] += 1;
        } else {
            col[index] += 1;
        }
    }

    int result = 0;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            result += ((row[i] + col[j]) % 2 == 1);
        }
    }

    cout << result << endl;
    
    return 0;
}
