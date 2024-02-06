#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    int m = pow(2, N - 1) * 2;
    cout << (m + 1) * (m + 1) << '\n';

    return 0;
}