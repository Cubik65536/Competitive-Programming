#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

pll operator+(pll a, pll b) {
    return {a.first + b.first, a.second + b.second};
}
pll operator-(pll a, pll b) {
    return {a.first - b.first, a.second - b.second};
}

vector<pair<pll, int>> all_subsets(const vector<pll> &dirs) {
	vector<pair<pll, int>> v{{}};
	for (const pll &d : dirs) {
		v.resize(2 * v.size());
		for (int i = 0; i < v.size() / 2; i++) {
			v[i + v.size() / 2] = {v[i].first + d, v[i].second + 1};
		}
	}
	return v;
}

struct hsh {
	size_t operator()(const pll &p) const {
		return p.first * 239 + p.second;
	}
};

int main() {
	int n;
	cin >> n;
	pll goal;
	cin >> goal.first >> goal.second;
	vector<pll> dirs(n);
	for (auto &d : dirs) {
		cin >> d.first >> d.second;
	}
	vector<pair<pll, int>> a = all_subsets(vector<pll>(begin(dirs), begin(dirs) + n / 2));
	vector<pair<pll, int>> b = all_subsets(vector<pll>(begin(dirs) + n / 2, end(dirs)));

	unordered_map<pll, map<int, int>, hsh> first_half;
	for (const auto &[offset, num] : a) {
		first_half[offset][num]++;
	}

	vector<ll> result(n + 1);

	for (const auto &[offset, num] : b) {
		auto it = first_half.find(goal - offset);
		if (it != end(first_half)) {
			for (const auto &[num2, ways] : it->second) {
				result[num + num2] += ways;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << result[i + 1] << endl;
	}

    return 0;
}