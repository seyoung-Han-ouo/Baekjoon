#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, X, S;
    cin >> N >> X >> S;

    bool canWin = false;

    while (N--) {
        int c, p;
        cin >> c >> p;

        if (c <= X && p > S) canWin = true;
    }

    if (canWin) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}