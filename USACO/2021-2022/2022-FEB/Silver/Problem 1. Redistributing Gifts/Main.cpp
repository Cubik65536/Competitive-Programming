#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using vb = vector<bool>;
using vi = vector<int>;

int main() {
    int n;
    cin >> n;

    vector<vi> perms(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int gift;
            cin >> gift;
            perms[i].push_back(--gift);
            if (gift == i) {
                for (int k = j + 1; k < n; k++) {
                    cin >> gift;
                }
                break;
            }
        }
    }

    vector<vb> visited(n, vb(n, false));

    for (int i = 0; i < n; i++) {
        queue<pii> current;
        current.push({i, i});
        while (current.size()) {
            pii next = current.front();
            current.pop();
            if (visited[next.first][next.second]) {
                continue;
            }
            visited[next.first][next.second] = true;
            for (int u: perms[next.second]) {
                current.push({next.first, u});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int gift: perms[i]) {
            if (visited[gift][i]) {
                cout << gift + 1 << endl;
                break;
            }
        }
    }

    return 0;
}
