#include <bits/stdc++.h>
 using namespace std;
 
struct edge {
    int cow;
    int to;
    bool is_first;
 
    edge() {};
    edge(int cow, int to, bool is_first) : cow(cow), to(to), is_first(is_first) {};
};
 
vector<edge> adj[100001];
bool cycleVisited[100001];
bool visited[100001];
bool getCereal[100001]; 
 
int hungry_cows = 0;

queue<int> order;
int ignoredEdges = -1;
int firstCereal = -1;
 
void findCycle(int current, int prev = -1) {
    cycleVisited[current] = true; 
    for (edge next : adj[current]) {
        if (cycleVisited[next.to]) {
            if (firstCereal == -1 && next.to != prev) {
                if (next.is_first) {
                    firstCereal = next.to; 
                } else {
                    firstCereal = current;
                }
                ignoredEdges = next.cow; 
                order.push(next.cow);
                getCereal[next.cow] = true;
            }
        } else {
            findCycle(next.to, current);
        }
    }
}

void dfs(int current) {
    visited[current] = true;
    for (edge next : adj[current]) {
        if (!visited[next.to] && next.cow != ignoredEdges) { 
            getCereal[next.cow] = true;
            order.push(next.cow);
            dfs(next.to);
        }
    }
}
 
int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(edge(i + 1, v, false));
        adj[v].push_back(edge(i + 1, u, true));
    }
 
    for (int i = 1; i <= m; ++i) {
        firstCereal = -1;
        ignoredEdges = -1;
        if (!visited[i]) {
            findCycle(i);
            if (firstCereal > 0) {
                dfs(firstCereal);
            } else {
                dfs(i);
            }
        }
    }
 
    for (int i = 1; i <= n; ++i) {
        if (!getCereal[i]) {
            hungry_cows++;
            order.push(i);
        } 
    }
 
    cout << hungry_cows << endl;
    while (!order.empty()) {
        cout << order.front() << endl; 
        order.pop();
    }
 
    return 0;
}
