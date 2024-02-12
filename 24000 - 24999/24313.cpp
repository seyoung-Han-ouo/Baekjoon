#include <iostream>
using namespace std;

int main() {
    int a1, a2, c, n;
    cin >> a1 >> a2 >> c >> n;

    if ((a1 * n + a2 <= c * n) && (a1 <= c)) cout << "1\n";
    else cout << "0\n";

    return 0;
}