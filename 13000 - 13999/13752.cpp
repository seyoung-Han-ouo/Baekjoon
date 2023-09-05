#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> k;

        for (int j = 0; j < k; j++) cout << '=';
        cout << '\n';
    }

    return 0;
}