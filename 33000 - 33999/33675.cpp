#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        if (N % 2 == 1) cout << "0\n";
        else {
            long long cnt = 1;
            for (int i = 0; i < N / 2; i++) cnt *= 2;

            cout << cnt << '\n';
        }
    }

    return 0;
}