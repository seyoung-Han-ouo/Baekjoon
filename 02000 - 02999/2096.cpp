#include <iostream>
using namespace std;

int mx[3], mn[3], arr[3], a[3], b[3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    while (N--) {
        for (int i = 0; i < 3; i++) {
            cin >> arr[i];

            a[i] = mx[i];
            b[i] = mn[i];
        }

        mx[0] = max(a[0], a[1]) + arr[0];
        mx[1] = max(max(a[0], a[1]), a[2]) + arr[1];
        mx[2] = max(a[1], a[2]) + arr[2];

        mn[0] = min(b[0], b[1]) + arr[0];
        mn[1] = min(min(b[0], b[1]), b[2]) + arr[1];
        mn[2] = min(b[1], b[2]) + arr[2];
    }

    cout << max(max(mx[0], mx[1]), mx[2]) << ' ' << min(min(mn[0], mn[1]), mn[2]) << '\n';

    return 0;
}