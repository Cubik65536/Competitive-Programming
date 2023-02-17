#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

struct edge {
    int i, a, v;
    edge(int i, int a, int v) : i(i), a(a), v(v) {}
};

const int MAX_N = 10e5;

ll sum;

int n;
vector<edge> adj[MAX_N];
bool visited[MAX_N];
set<int> path;

int minV = INT_MAX;
void processLoop(int current, int end) {
    if (path.count(current)) {
        return;
    }
    path.insert(current);
    for (edge next : adj[current]) {
        if (next.i == end) {
            minV = min(minV, next.v);
            sum -= minV;
            return;
        }
        minV = min(minV, next.v);
        processLoop(next.a, end);
    }
}

void dfs(int current) {
    visited[current] = true; 
    for (edge next : adj[current]) {
        if (path.count(next.a)) {
            return;
        }
        if (!visited[next.a]) {
            dfs(next.a);
        } else {
            minV = INT_MAX;
            processLoop(next.a, next.i);
            return;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, v;
        cin >> a >> v;
        a--;
        sum += v;
        adj[i].push_back(edge(i, a, v));
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    cout << sum << endl;

    return 0;
}
