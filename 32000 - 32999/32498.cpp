#include <iostream>
using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;

    while (n--) {
        int r;
        cin >> r;

        if (r % 2 == 1) cnt++;
    }

    cout << cnt << '\n';

    return 0;
}