#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int result = 0;

    if (C * 2 < A + B) {
        int cnt = min(X, Y);

        result += (cnt * C * 2);
        X -= cnt;
        Y -= cnt;
    }

    int sum1 = (A * X + B * Y);
    int sum2 = C * 2 * max(X, Y);

    result += min(sum1, sum2);

    cout << result << '\n';
}