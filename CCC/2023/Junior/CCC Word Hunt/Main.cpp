#include<bits/stdc++.h>

using namespace std;

const int MAX_R_C = 100;

string W;
int R, C;
int word_length;
char grid[MAX_R_C][MAX_R_C];

int result;

void find_horizontal(int step, int direction, int r, int c, bool turned);
void find_vertical(int step, int direction, int r, int c, bool turned);
void find_diagonal(int step, int r_direction, int c_direction, int r, int c, bool turned);

void find_horizontal(int step, int direction, int r, int c, bool turned) {
    if (r < 0 || r >= R || c < 0 || c >= C) return;
    if (grid[r][c] == W[step]) {
        if (step == word_length - 1) {
            result++;
            return;
        }
        find_horizontal(step + 1, direction, r, c + direction, turned);
        if (!turned && step > 0) {
            find_vertical(step + 1, -1, r - 1, c, true);
            find_vertical(step + 1,  1, r + 1, c, true);
        }
    }
}

void find_vertical(int step, int direction, int r, int c, bool turned) {
    if (r < 0 || r >= R || c < 0 || c >= C) return;
    if (grid[r][c] == W[step]) {
        if (step == word_length - 1) {
            result++;
            return;
        }
        find_vertical(step + 1, direction, r + direction, c, turned);
        if (!turned && step > 0) {
            find_horizontal(step + 1, -1, r, c - 1, true);
            find_horizontal(step + 1,  1, r, c + 1, true);
        }
    }
}

void find_diagonal(int step, int r_direction, int c_direction, int r, int c, bool turned) {
    if (r < 0 || r >= R || c < 0 || c >= C) return;
    if (grid[r][c] == W[step]) {
        if (step == word_length - 1) {
            result++;
            return;
        }
        find_diagonal(step + 1, r_direction, c_direction, r + r_direction, c + c_direction, turned);
        if (!turned && step > 0) {
            find_diagonal(step + 1, r_direction, c_direction * -1, r + r_direction, c - c_direction, true);
            find_diagonal(step + 1, r_direction * -1, c_direction, r - r_direction, c + c_direction, true);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> W;
    word_length = W.length();

    cin >> R >> C;

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            char letter;
            cin >> letter;
            grid[r][c] = letter;
        }
    }
    
    result = 0;

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            find_horizontal(0, -1, r, c, false);
            find_horizontal(0,  1, r, c, false);
            find_vertical(0, -1, r, c, false);
            find_vertical(0,  1, r, c, false);
            find_diagonal(0, -1, -1, r, c, false);
            find_diagonal(0, -1,  1, r, c, false);
            find_diagonal(0,  1, -1, r, c, false);
            find_diagonal(0,  1,  1, r, c, false);
        }
    }

    cout << result << endl;
    
    return 0;
}
