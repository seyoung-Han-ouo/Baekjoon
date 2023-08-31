#include <iostream>
#include <algorithm>
using namespace std;

int k;
int S[13];
int result[6];

void dfs(int cnt, int now) {
    if (cnt == 6) {
        for (int i = 0; i < 6; i++)
            cout << result[i] << ' ';
        cout << '\n';

        return;
    }

    for (int i = now; i < k; i++) {
        result[cnt] = S[i];

        dfs(cnt + 1, i + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (true) {
        cin >> k;

        if (k == 0) break;

        for (int i = 0; i < k; i++) cin >> S[i];

        sort(S, S + k);

        dfs(0, 0);
        cout << '\n';
    }

    return 0;
}