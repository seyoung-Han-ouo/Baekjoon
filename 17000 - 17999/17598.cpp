#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tiger = 0;

    for (int i = 0; i < 9; i++) {
        string s;
        cin >> s;

        if (s == "Tiger") tiger++;
    }

    if (tiger >= 5) cout << "Tiger\n";
    else cout << "Lion\n";

    return 0;
}