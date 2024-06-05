#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;          // 참가자의 수
    int tSize[6];   // 티셔츠 사이즈별 신청자의 수
    int T, P;       // 티셔츠와 펜의 묶음 수

    // 입력
    cin >> N;
    for (int i = 0; i < 6; i++) cin >> tSize[i];
    cin >> T >> P;

    // 티셔츠 묶음 개수 구하기
    int tCnt = 0;
    for (int i = 0; i < 6; i++)
        tCnt += (tSize[i] / T + (tSize[i] % T > 0));

    // 출력
    cout << tCnt << '\n';
    cout << N / P << ' ' << N % P << '\n';

    return 0;
}