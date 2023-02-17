#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

int main()
{
    int N;
    cin >> N;

    int T;
    cin >> T;

    vector<pii> trees;
    for (int i = 0; i < T; i++)
    {
        int R, C;
        cin >> R >> C;
        trees.push_back({R, C});
    }

    T++;
    trees.push_back({0, 0});

    int result = 0;

    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < T; j++)
        {
            if (i == j && i != T - 1)
                continue;

            int U = trees[i].first;
            int L = trees[j].second;

            int current = INT_MAX;

            for (int k = 0; k < T; k++)
            {
                if (k == i || k == j)
                    continue;
                if (trees[k].first > U && trees[k].second > L)
                {
                    int dx = trees[k].first - U - 1;
                    int dy = trees[k].second - L - 1;
                    current = min(current, max(dx, dy));
                }
            }

            int temp = min(N - U, N - L);
            if (temp < current)
            {
                current = temp;
            }

            result = max(result, current);
        }
    }

    cout << result << endl;

    return 0;
}
