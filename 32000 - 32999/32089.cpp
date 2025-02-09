#include <iostream>
using namespace std;

int arr[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        int n;
        cin >> n;

        if (n == 0) break;

        int result = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];

            if (i >= 2) result = max(result, arr[i] + arr[i - 1] + arr[i - 2]);
        }

        cout << result << '\n';
    }

    return 0;
}