#include <iostream>
using namespace std;

int P[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> P[i];

        for (int j = 1; j <= i / 2; j++)
            P[i] = min(P[i], P[i - j] + P[j]);
    }

    cout << P[N] << '\n';

    return 0;
}