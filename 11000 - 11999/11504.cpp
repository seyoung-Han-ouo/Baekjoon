#include <iostream>
using namespace std;

int N, M;
int X[10], Y[10];
int num[101];

int makeNum(int start, int arr[]);

// 배열을 int로 바꾸기
int makeNum(int start, int arr[]) {
    int n = 0;

    for (int i = 0; i < M; i++) {
        int idx = (start + i) % N;

        n = n * 10 + arr[idx];
    }

    return n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        // 입력
        cin >> N >> M;
        for (int i = 0; i < M; i++) cin >> X[i];
        for (int i = 0; i < M; i++) cin >> Y[i];
        for (int i = 0; i < N; i++) cin >> num[i];

        int x = makeNum(0, X);
        int y = makeNum(0, Y);

        // 게임을 승리할 수 있는 가짓수 구하기
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            int z = makeNum(i, num);

            if (x <= z && z <= y) cnt++;
        }

        // 출력
        cout << cnt << '\n';
    }

    return 0;
}