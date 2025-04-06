#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, big = 0;
    cin >> N;

    while (N--) {
        int a, b, c, n = 0;
        cin >> a >> b >> c;

        if (a == b && b == c) n = 10000 + a * 1000;
        else if (a == b || a == c) n = 1000 + a * 100;
        else if (b == c) n = 1000 + b * 100;
        else n = max(a, max(b, c)) * 100;

        big = max(big, n);
    }

    cout << big << '\n';

    return 0;
}