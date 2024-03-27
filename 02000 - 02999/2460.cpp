#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int now = 0, mx = 0;

    for (int i = 0; i < 10; i++) {
        int a, b;
        cin >> a >> b;

        now = now - a + b;
        mx = max(mx, now);
    }

    cout << mx << '\n';

    return 0;
}