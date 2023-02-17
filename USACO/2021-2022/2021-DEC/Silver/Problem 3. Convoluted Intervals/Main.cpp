#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pii> intervals(n);
    for (auto &interval: intervals) {
        cin >> interval.first >> interval.second;
    }

    vector<ll> winStart(2 * m + 1), winEnd(2 * m + 1);
    vector<ll> aFrequency(m + 1), bFrequency(m + 1);
    for (int i = 0; i < n; i++) {
        aFrequency[intervals[i].first]++;
        bFrequency[intervals[i].second]++;
    }
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            winStart[i + j] += aFrequency[i] * aFrequency[j];
            winEnd[i + j] += bFrequency[i] * bFrequency[j];
        }
    }

    ll winCount = 0;
    for (int i = 0; i <= 2 * m; i++) {
        winCount += winStart[i];
        cout << winCount << endl;
        winCount -= winEnd[i];
    }

    return 0;
}
