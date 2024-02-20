#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int P;
    cin >> P;

    while (P--) {
        int T, arr[20];
        cin >> T;

        int cnt = 0;

        for (int i = 0; i < 20; i++) {
            cin >> arr[i];

            for (int j = 0; j < i; j++) {
                if (arr[j] > arr[i]) {
                    cnt += i - j;
                    break;
                }
            }

            sort(arr, arr + i + 1);
        }

        cout << T << ' ' << cnt << '\n';
    }

    return 0;
}