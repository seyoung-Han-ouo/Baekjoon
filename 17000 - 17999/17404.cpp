#include <iostream>
using namespace std;

#define MAX 987654321

int N, result = MAX;
int house[1000][3];
int dp[1000][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 3; j++) cin >> house[i][j];

    for (int rgb = 0; rgb < 3; rgb++) {
        dp[0][0] = dp[0][1] = dp[0][2] = MAX;
        dp[0][rgb] = house[0][rgb];

        for (int i = 1; i < N; i++) {
            dp[i][0] = house[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = house[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = house[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
        }

        for (int i = 0; i < 3; i++) {
            if (i != rgb) result = min(result, dp[N - 1][i]);
        }
    }

    cout << result << '\n';

    return 0;
}