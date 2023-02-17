#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second

using pii = pair<int, int>;

const int MAX_N = 1000 + 5;
bool visited[MAX_N][MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int M, N;
    cin >> M >> N;

    vector<vector<pii>> jumps(1e6 + 5);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int jump;
            cin >> jump;
            jumps[jump].push_back({i + 1, j + 1});
        }
    }

    queue<pii> q;
    q.push({N, M});
    visited[N][M] = true;

    while (!q.empty()) {
        pii u = q.front();
        q.pop();
        
        int r = u.x;
        int c = u.y;
        
        for (pii v : jumps[r * c]) {
            if (v.x == 1 && v.y == 1) {
                cout << "yes" << endl;
                return 0;
            } 
            if (!visited[v.x][v.y]) {
                visited[v.x][v.y] = true;
                q.push(v);
            }
        }
    }

    cout << "no" << endl;
    
    return 0;
}
