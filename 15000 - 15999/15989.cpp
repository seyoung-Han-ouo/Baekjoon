#include <iostream>
using namespace std;

int arr[10001] = { 1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i < 4; i++)
        for (int j = i; j < 10001; j++)
            arr[j] += arr[j - i];

    int T, n;
    cin >> T;

    while (T--) {
        cin >> n;
        cout << arr[n] << '\n';
    }

    return 0;
}