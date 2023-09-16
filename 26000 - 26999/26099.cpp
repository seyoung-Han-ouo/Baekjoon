#include <iostream>
using namespace std;

int main() {
    long N, cnt = -1;

    cin >> N;

    for (long i = N / 5; i >= 0; i--) {
        long sugar = N - 5 * i;

        if (sugar % 3 == 0) {
            cnt = sugar / 3 + i;
            break;
        }
    }

    cout << cnt << '\n';

    return 0;
}