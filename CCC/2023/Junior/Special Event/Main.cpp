#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    int attent[5] = {0};

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < 5; j++) {
            if (s[j] == 'Y') {
                attent[j]++;
            }
        }
    }

    int max = 0;
    vector<int> days;

    for (int i = 0; i < 5; i++) {
        int current = attent[i];
        if (current > max)  {
            max = current;
            days.clear();
            days.push_back(i + 1);
        } else if (current == max) {
            days.push_back(i + 1);
        }
    }

    for (int i = 0; i < days.size() - 1; i++) {
        cout << days[i] << ",";
    }

    cout << days[days.size() - 1] << endl;
    
    return 0;
}
