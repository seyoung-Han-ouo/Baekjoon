#include <iostream>
using namespace std;

int arr[2][100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        for (int i = 0; i < 2; i++)
            for (int j = 1; j <= n; j++) cin >> arr[i][j];

        for (int i = 2; i <= n; i++) {
            arr[0][i] += max(arr[1][i - 1], arr[1][i - 2]);
            arr[1][i] += max(arr[0][i - 1], arr[0][i - 2]);
        }

        cout << max(arr[0][n], arr[1][n]) << '\n';
    }

    return 0;
}