#include <iostream>
using namespace std;

int p1, p2, p3, x1, x2, x3;

int findNum();

int findNum() {
    for (int i = 1; i <= p1 * p2 * p3; i++) {
        if (i % p1 == x1 && i % p2 == x2 && i % p3 == x3) return i;
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> p1 >> p2 >> p3 >> x1 >> x2 >> x3;

    cout << findNum() << '\n';

    return 0;
}