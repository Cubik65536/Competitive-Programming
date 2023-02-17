// #include<bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
 
using namespace std;
 
void dfs(const vector<vector<int>>& edges, vector<int>& component, const int currv, const int id) {
    for(int child: edges[currv]) {
        if(component[child] != id) {
            component[child] = id;
            dfs(edges, component, child, id);
        }
    }
}
 
void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(n);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    vector<int> component(n);
    iota(component.begin(), component.end(), 0);
    for(int i = 0; i < n; i++) {
        if(component[i] == i) {
            dfs(edges, component, i, i);
        }
    }

    if(component[0] == component[n - 1]) {
        cout << "0" << endl;
        return;
    }

    vector<vector<int>> componentToVertices(n);
    for(int i = 0; i < n; i++) {
        componentToVertices[component[i]].push_back(i);
    }

    long long result = 1e18;
    vector<long long> srcCost(n, 1e9);
    vector<long long> dstCost(n, 1e9);
    int srcIndex = 0;
    int dstIndex = 0;
    for(int i = 0; i < n; i++) {
        while(srcIndex < componentToVertices[component[0]].size()) {
            srcCost[component[i]] = min(srcCost[component[i]], (long long)abs(i - componentToVertices[component[0]][srcIndex]));
            if(componentToVertices[component[0]][srcIndex] < i) {
                srcIndex++;
            } else {
                break;
            }
        }
        if(srcIndex) {
            srcIndex--;
        }
        while(dstIndex < componentToVertices[component[n-1]].size()) {
            dstCost[component[i]] = min(dstCost[component[i]], (long long)abs(i - componentToVertices[component[n-1]][dstIndex]));
            if(componentToVertices[component[n-1]][dstIndex] < i) {
                dstIndex++;
            } else {
                break;
            }
        }
        if(dstIndex) {
            dstIndex--;
        }
    }

    for(int i = 0; i < n; i++) {
        result = min(result, srcCost[i]*srcCost[i] + dstCost[i]*dstCost[i]);
    }
    cout << result << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}
