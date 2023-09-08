#include <iostream>
using namespace std;

long long arr[1000001] = { 0, 1, 2, 4 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T, i = 4;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        for (i; i <= n; i++)
            arr[i] = (arr[i - 1] + arr[i - 2] + arr[i - 3]) % 1000000009;

        cout << arr[n] << '\n';
    }

    return 0;
}