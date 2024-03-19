#include <iostream>
using namespace std;

int last[1000001];
int dp[1000001];

void print(int N);

void print(int N) {
    cout << dp[N] << '\n' << N;

    while (N > 1) {
        cout << ' ' << last[N];
        N = last[N];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + 1;
        last[i] = i - 1;

        if (i % 3 == 0) {
            int cnt = dp[i / 3] + 1;

            if (dp[i] > cnt) {
                dp[i] = cnt;
                last[i] = i / 3;
            }
        }

        if (i % 2 == 0) {
            int cnt = dp[i / 2] + 1;

            if (dp[i] > cnt) {
                dp[i] = cnt;
                last[i] = i / 2;
            }
        }
    }

    print(N);

    return 0;
}