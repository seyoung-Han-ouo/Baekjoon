#include <iostream>
using namespace std;

int arr[100][100];
long long dp[100][100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> arr[i][j];

    dp[0][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 0) continue;

            int x = j + arr[i][j];
            int y = i + arr[i][j];

            if (x < N) dp[i][x] += dp[i][j];
            if (y < N) dp[y][j] += dp[i][j];
        }
    }

    cout << dp[N - 1][N - 1] << '\n';

    return 0;
}