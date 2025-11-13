#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    int cnt = 0;

    while (N--) {
        int s, c, a, r;
        cin >> s >> c >> a >> r;

        if (s >= 1000 || c >= 1600 || a >= 1500 || (r <= 30 && r != -1)) cnt++;
    }

    cout << cnt << '\n';

    return 0;
}