#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    string max_name;
    int max_bid = INT_MIN;

    while (N--){
        string name;
        int bid;

        cin >> name >> bid;

        if (bid > max_bid) {
            max_name = name;
            max_bid = bid;
        }
    }

    cout << max_name << endl;

    return 0;
}
