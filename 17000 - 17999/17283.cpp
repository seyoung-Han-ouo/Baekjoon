#include <iostream>
#include <cmath>
using namespace std;

int tree(int len, double r);

int tree(int len, double r) {
    int result = 0;
    int cnt = 1;

    while (true) {
        cnt *= 2;
        len = floor(len * r);

        if (len <= 5) break;

        result += (len * cnt);
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int L, R;
    cin >> L >> R;

    cout << tree(L, R / 100.0) << '\n';

    return 0;
}