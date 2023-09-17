#include <iostream>
using namespace std;

int A, B, cnt = -1;

void AtoB(long n, int now);

void AtoB(long n, int now) {
    if (n == B) {
        if (cnt == -1) cnt = now;
        else cnt = min(cnt, now);

        return;
    }

    if (n * 2 <= B) AtoB(n * 2, now + 1);

    if (n * 10 + 1 <= B) AtoB(n * 10 + 1, now + 1);
}

int main() {
    cin >> A >> B;

    AtoB(A, 1);

    cout << cnt << '\n';

    return 0;
}