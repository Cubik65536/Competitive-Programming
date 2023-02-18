#include<bits/stdc++.h>

using namespace std;

const int MAX_C = 200000;

bool wet[2][MAX_C + 1] = {{false}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int C;
    cin >> C;

    int tile;
    int tile_count = 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < C; j++) {
            cin >> tile;
            if (tile == 1) {
                wet[i][j] = true;
                tile_count++;
            }
        }
    }

    int result = tile_count * 3;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < C; j++) {
            if (wet[i][j]) {
                if (j != 0) {
                    if (wet[i][j - 1]) result--;
                }
                if (j != C - 1) {
                    if (wet[i][j + 1]) result--;
                }
                if (j % 2 == 0) {
                    if (i == 0) {
                        if (wet[i + 1][j]) result--;
                    } else {
                        if (wet[i - 1][j]) result--;
                    }
                }
            }
        }
    }
    
    cout << result << endl;

    return 0;
}
