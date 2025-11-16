#include <iostream>
using namespace std;

bool arr[1000000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int l, r, x;
    cin >> l >> r >> x;

    for (int i = l; i <= r; i++) arr[i | x] = true;

    for (int i = 0; ; i++) {
        if (!arr[i]) {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}