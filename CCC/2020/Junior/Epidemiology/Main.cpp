#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int P, N, R;
    cin >> P >> N >> R;

    int day = 0;
    int infected = N;
    int last_infected = N;

    while (true) {
        if (infected > P) break;
        day++;
        last_infected *= R;
        infected += last_infected;
    }

    cout << day << endl;

    return 0;
}
