#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string A, B;
    char c;

    cin >> A >> c >> B;

    if (c == '+') {
        if (A.length() < B.length()) {
            string C = A;
            A = B;
            B = C;
        }

        A[A.length() - B.length()] += 1;

        cout << A << '\n';
    }
    else {
        cout << A;
        for (int i = 1; i < B.length(); i++) cout << 0;
        cout << "\n";
    }

    return 0;
}