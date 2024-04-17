#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N;

        vector<int> coins(N);
        vector<int> dp(10001);

        for (int i = 0; i < N; i++) cin >> coins[i];
        cin >> M;

        dp[0] = 1;

        for (int coin : coins) {
            for (int i = coin; i <= M; i++)
                dp[i] += dp[i - coin];
        }

        cout << dp[M] << '\n';
    }

    return 0;
}