#include <iostream>
using namespace std;

int speed[101][2];

void fill(int N, int idx);

void fill(int N, int idx) {
    int now = 0;
    int loc = 0;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        loc += a;

        while (now <= loc) {
            speed[now][idx] = b;
            now++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    fill(N, 0);
    fill(M, 1);

    int mx = 0;
    for (int i = 1; i <= 100; i++)
        mx = max(mx, speed[i][1] - speed[i][0]);

    cout << mx << '\n';

    return 0;
}