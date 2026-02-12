#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, d;
    cin >> n >> d;

    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        int num = i;

        while (num > 0) {
            if (num % 10 == d) cnt++;
            num /= 10;
        }
    }

    cout << cnt << '\n';

    return 0;
}