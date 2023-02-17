#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    ll result = 0;
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && h[st.top()] < h[i]) {
            result += i - st.top() + 1;
            st.pop();
        }
        if (!st.empty()) {
            result += i - st.top() + 1;
            if (h[st.top()] == h[i]) {
                st.pop();
            }
        }
        st.push(i);
    } 

    cout << result << endl;

    return 0;
}
