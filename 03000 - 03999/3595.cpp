#include <iostream>
using namespace std;

int a, b, c;
int mn = 10000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        if (n % i != 0) continue;

        int num = (n / i);

        for (int j = 1; j <= num; j++) {
            if (num % j != 0) continue;

            int k = num / j;
            int area = (i * j * 2) + (i * k * 2) + (j * k * 2);

            if (area < mn) {
                mn = area;
                a = i;
                b = j;
                c = k;
            }
        }
    }

    cout << a << ' ' << b << ' ' << c << '\n';

    return 0;
}