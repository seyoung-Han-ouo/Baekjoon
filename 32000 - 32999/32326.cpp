#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int r, g, b;
    cin >> r >> g >> b;
    cout << r * 3 + g * 4 + b * 5 << '\n';

    return 0;
}