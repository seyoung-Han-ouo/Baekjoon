#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

unordered_set<int> coins;
vector<int> dp(10001, -1);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        dp[num] = 1;
        coins.insert(num);
    }

    for (int i = 1; i <= k; i++) {
        if (dp[i] > 0) {
            for (int coin : coins) {
                int idx = coin + i;

                if (idx > 10000) continue;

                if (dp[idx] == -1)
                    dp[idx] = dp[i] + 1;
                else
                    dp[i + coin] = min(dp[i] + 1, dp[i + coin]);
            }
        }
    }

    cout << dp[k] << '\n';

    return 0;
}