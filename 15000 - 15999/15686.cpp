#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M, result = 10000000;
int d[14];
vector<pair<int, int>> h, c;

void dfs(int now, int cnt);

void dfs(int now, int cnt) {
    if (cnt == M) {
        int sum = 0;

        for (int i = 0; i < h.size(); i++) {
            int mn = 10000000;

            for (int j = 0; j < M; j++)
                mn = min(mn, abs(h[i].first - c[d[j]].first) + abs(h[i].second - c[d[j]].second));
            sum += mn;
        }

        result = min(result, sum);

        return;
    }

    for (int i = now; i < c.size(); i++) {
        d[cnt] = i;
        dfs(i + 1, cnt + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int n;
            cin >> n;

            if (n == 1) h.push_back({ i, j });
            if (n == 2) c.push_back({ i, j });
        }
    }

    dfs(0, 0);

    cout << result << '\n';

    return 0;
}