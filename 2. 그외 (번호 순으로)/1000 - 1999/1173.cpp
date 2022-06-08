#include <iostream>
using namespace std;

int main() {
    int N; // 운동한 시간
    int m, M; // 초기 맥박 m, 최대 맥박 M, 
    int T, R; // 증가하는 맥박 T, 감소하는 맥박 R

    // 입력
    cin >> N >> m >> M >> T >> R;

    // 운동이 불가능한 경우
    if (M - m < T) 
        cout << -1;
    else {
        int time = 0; // 걸린 시간
        int X = m; // 현재 맥박

        while (N > 0) {
            // 운동
            if (X + T <= M) {
                X += T; // 맥박 증가

                N--;
                time++;
            }
            // 휴식
            else {
                if (X - R < m)
                    X = m;
                else
                    X -= R;
                time++;
            }
        }

        // 출력
        cout << time;
    }

    return 0;
}