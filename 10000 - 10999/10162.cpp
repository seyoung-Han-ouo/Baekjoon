#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    if (T % 10 != 0) cout << "-1\n";
    else {
        int A = T / 300;
        T %= 300;

        int B = T / 60;
        T %= 60;

        int C = T / 10;

        cout << A << ' ' << B << ' ' << C << '\n';
    }

    return 0;
}