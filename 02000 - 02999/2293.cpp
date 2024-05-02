#include <iostream>
using namespace std;

int dp[10001] = { 1, };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int coin;
        cin >> coin;

        for (int j = coin; j <= k; j++) dp[j] += dp[j - coin];
    }

    cout << dp[k] << '\n';

    return 0;
}