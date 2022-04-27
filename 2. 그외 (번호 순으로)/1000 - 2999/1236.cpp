#include <iostream>
using namespace std;

int main() {
    bool sero[51] = { false };
    bool garo[51] = { false };

    // 세로 크기 N, 가로 크기 M
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        // 경비원이 있는 칸 체크
        for (int j = 0; j < M; j++) {
            if (s[j] == 'X') {
                sero[i] = true;
                garo[j] = true;
            }
        }
    }

    // 추가해야 하는 경비원의 최솟값 찾기
    int count1 = N;
    for (int i = 0; i < N; i++)
        if (sero[i] == true) count1--;

    int count2 = M;
    for (int i = 0; i < M; i++)
        if (garo[i] == true) count2--;

    // 출력
    if (count1 > count2)
        cout << count1;
    else
        cout << count2;

    return 0;
}