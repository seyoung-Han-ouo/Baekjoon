#include <iostream>
using namespace std;

int e, f, c;

int drink(int n);

int drink(int n) {
    int cnt = 0;

    while (n >= c) {
        n -= c;
        n++;
        cnt++;
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> e >> f >> c;

    cout << drink(e + f) << '\n';

    return 0;
}