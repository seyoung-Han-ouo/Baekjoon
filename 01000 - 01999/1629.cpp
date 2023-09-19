#include <iostream>
using namespace std;

int main() {
    long long A, B, C;
    cin >> A >> B >> C;

    long long result = 1;

    while (B > 0) {
        if (B % 2 == 1) result = (result * A) % C;

        A = (A * A) % C;
        B /= 2;
    }

    cout << result << '\n';

    return 0;
}