#include <iostream>
using namespace std;

#define MOD 1000000000

int N, dp[101][10][1025];

int dynamic(int n, int num, int bit);

int dynamic(int n, int num, int bit) {
    if (dp[n][num][bit] != 0) return dp[n][num][bit];

    if (n == N) return bit == 1023;

    int result = 0;

    if (num > 0) result += dynamic(n + 1, num - 1, bit | (1 << (num - 1)));
    if (num < 9) result += dynamic(n + 1, num + 1, bit | (1 << (num + 1)));

    result %= MOD;

    return dp[n][num][bit] = result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    int result = 0;

    for (int i = 1; i < 10; i++) {
        result += dynamic(1, i, 1 << i);
        result %= MOD;
    }

    cout << result << '\n';

    return 0;
}