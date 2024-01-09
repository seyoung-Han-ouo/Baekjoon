#include <iostream>
using namespace std;

long long pn[91][2] = { {0, 0}, {0, 1} };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for (int i = 2; i <= N; i++) {
        pn[i][0] = pn[i - 1][0] + pn[i - 1][1];
        pn[i][1] = pn[i - 1][0];
    }

    cout << pn[N][0] + pn[N][1] << '\n';

    return 0;
}