#include <iostream>
using namespace std;

int main() {
    int N, c; // 파일의 개수 N, 클러스터의 크기 c
    int file[51]; // 파일의 크기

    // 입력
    cin >> N;
    for (int i = 0; i < N; i++)
        scanf("%d", &file[i]);
    cin >> c;

    long long cnt = 0; // 사용 중인 클러스터 수

    // 사용 중인 클러스터 수 구하기
    for (int i = 0; i < N; i++) {
        // 파일 크기가 0이면 클러스터를 사용하지 않는다.
        if (file[i] == 0) continue;

        if (file[i] <= c) cnt++;
        else {
            cnt += (file[i] / c);

            if (file[i] % c != 0) cnt++;
        }
    }

    // 출력
    cout << cnt * c << endl;

    return 0;
}