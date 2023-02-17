#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

void solve() {
    int m, n, k;
    cin >> m >> n >> k;
    vi emailToFolder(n);
    vector<vi> folderToEmail(m);
    vector<vi> fileTiming(m);
    vector<bool> filed(n);
    vector<bool> skipped(n);
    vector<bool> inwindow(n);
    for (int i = 0; i < n; i++) {
        cin >> emailToFolder[i];
        fileTiming[max(0, --emailToFolder[i] - k + 1)].push_back(i);
        folderToEmail[emailToFolder[i]].push_back(i);
    }
    int currentemail = 0;
    int lhsemail = 0;
    int numinwindow = 0;
    int rhsemail = n - 1;
    auto fileemail = [&](int id) -> void {
        if (inwindow[id]) {
            inwindow[id] = false;
            numinwindow--;
        }
        assert(!filed[id]);
        filed[id] = true;
    };
    int bottom = 0;
    for (int i = 0; i < m; i++) {
        if (i > bottom && i + k <= m)
            bottom++;
        for (int out: fileTiming[i]) {
            if (inwindow[out]) {
                fileemail(out);
            }
        }
        while (folderToEmail[i].size() && currentemail <= folderToEmail[i].back()) {
            if (numinwindow == k) {
                while (!inwindow[lhsemail]) {
                    lhsemail++;
                }
                skipped[lhsemail] = true;
                inwindow[lhsemail] = false;
                numinwindow--;
            }
            if (emailToFolder[currentemail] >= i && emailToFolder[currentemail] <= i + k - 1) {
                filed[currentemail++] = true;
                continue;
            }
            inwindow[currentemail++] = true;
            numinwindow++;
        }
        while (currentemail < n && numinwindow < k) {
            if (emailToFolder[currentemail] >= i && emailToFolder[currentemail] <= i + k - 1) {
                filed[currentemail++] = true;
                continue;
            }
            inwindow[currentemail++] = true;
            numinwindow++;
        } 
        if (currentemail == n) {
            while (numinwindow < k) {
                if (rhsemail < 0) {
                    break;
                }
                if (!skipped[rhsemail]) {
                    rhsemail--;
                    continue;
                }
                if (emailToFolder[rhsemail] < bottom) {
                    cout << "NO\n";
                    return;
                }
                if (emailToFolder[rhsemail] <= bottom + k - 1) {
                    filed[rhsemail--] = true;
                    continue;
                }
                inwindow[rhsemail--] = true;
                numinwindow++;
            }
        }
    }

    for (auto out: filed) {
        if (!out) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
