#include <iostream>
using namespace std;

int arr[1001] = { 1001, };
int dp[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, mx = 0;

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    for (int i = 1; i <= N; i++) {
        dp[i] = 1;

        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[i]) 
                dp[i] = max(dp[i], dp[j] + 1);
        }

        mx = max(mx, dp[i]);
    }

    cout << mx << '\n';

    return 0;
}