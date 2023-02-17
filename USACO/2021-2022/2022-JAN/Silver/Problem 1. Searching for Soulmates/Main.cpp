#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

void solve() {
	ll a, b;
	cin >> a >> b;

	if (a == b) {
		cout << "0" << endl;
		return;
	}

	vll div1 = {a}, div2 = {b};
	
	while (a > 1) {
		if (a % 2) {
			a++;
		} else {
			a /= 2;
		}
		div1.push_back(a);
	}
	div1.push_back(1);

	while (b > 1) {
		if (b % 2) {
			b--;
		} else {
			b /= 2;
		}
		div2.push_back(b);
	}
	div2.push_back(1);

	ll result = LLONG_MAX;
	for (int i = 0; i < div1.size(); i++) {
		for (int j = 0; j < div2.size(); j++) {
			if (div1[i] < div2[j]) {
				result = min(div2[j] - div1[i] + i + j, result);
			}
		}
	}

	cout << result << endl;
}

int main() {
	int t;
	cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
