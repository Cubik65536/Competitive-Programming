#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 2e5;

set<pair<string, string>> same_group;
set<pair<string, string>> diff_group;

int main() {
    int X;
    cin >> X;
    for (int i = 0; i < X; i++) {
        string name1, name2;
        cin >> name1 >> name2;
        same_group.emplace(make_pair(min(name1, name2), max(name1, name2)));
    }

    int Y;
    cin >> Y;
    for (int i = 0; i < Y; i++) {
        string name1, name2;
        cin >> name1 >> name2;
        diff_group.emplace(make_pair(min(name1, name2), max(name1, name2)));
    }

    int G;
    cin >> G;

    int result = 0;

    set<pair<string, string>> pairs;
    while(G--) {
        vector<string> names(3);
        for (int i = 0; i < 3; i++) {
            cin >> names[i];
        }
        for (int i = 0; i < 3; i++) {
            for (int j = i + 1; j < 3; j++) {
                if (i == j) continue;
                pair<string, string> p = make_pair(min(names[i], names[j]), max(names[i], names[j]));
                pairs.emplace(p);
                if (diff_group.find(p) != diff_group.end()) {
                    result++;
                }
            }
        }
    }

    for (auto p : same_group) {
        if (pairs.find(p) == pairs.end()) {
            result++;
        }
    }

    cout << result << endl;
    
    return 0;
}
