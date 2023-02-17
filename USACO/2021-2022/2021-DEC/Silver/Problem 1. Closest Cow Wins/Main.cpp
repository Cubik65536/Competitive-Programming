#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

int main() {
    int k, m, n;
    cin >> k >> m >> n;

    vector<pii> patches(k + m);
    for (int i = 0; i < k; i++) {
        cin >> patches[i].first >> patches[i].second;
    }
    for (int i = k; i < k + m; i++) {
        cin >> patches[i].first;
        patches[i].second = -1;
    }

    sort(patches.begin(), patches.end());

    vector<ll> increases;
    int lastI = -1;
    ll sumRange = 0;
    for (int i = 0; i < patches.size(); i++) {
        if (patches[i].second == -1) {
            if (lastI == -1) {
                increases.push_back(sumRange);
            } else {
                ll currentResult = 0;
                ll bestResult = 0;
                for (int j = lastI + 1, r = lastI; j < i; j++) {
                    while (r + 1 < i && (patches[r + 1].first - patches[j].first) * 2 < patches[i].first - patches[lastI].first) {
                        currentResult += patches[++r].second;
                    }
                    bestResult = max(bestResult, currentResult);
                    currentResult -= patches[j].second;
                }
                assert(2 * bestResult >= sumRange);
                increases.push_back(bestResult);
                increases.push_back(sumRange - bestResult);
            }
            lastI = i;
            sumRange = 0;
        } else {
            sumRange += patches[i].second;
        }
    }

    increases.push_back(sumRange);
    sort(rbegin(increases), rend(increases));
    increases.resize(n);

    ll result = 0;
    for (auto i : increases) {
        result += i;
    }
    cout << result << endl;

    return 0;
}
