#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int A, B, C;
    cin >> A >> B >> C;

    if (A + B == C) cout << "correct!\n";
    else cout << "wrong!\n";

    return 0;
}