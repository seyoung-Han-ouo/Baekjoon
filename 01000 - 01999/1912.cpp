#include <iostream>
using namespace std;

int dp[100000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    cin >> dp[0];
    int result = dp[0];

    for (int i = 1; i < n; i++) {
        cin >> dp[i];

        dp[i] = max(dp[i - 1] + dp[i], dp[i]);
        result = max(result, dp[i]);
    }

    cout << result << '\n';

    return 0;
}