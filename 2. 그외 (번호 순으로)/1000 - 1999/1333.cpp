#include <iostream>
using namespace std;

int main() {
    // 총 노래가 N곡, 노래의 길이 L초, 전화벨이 울리는 간격 D초
    int N, L, D;
    cin >> N >> L >> D;

    int btime; // 전화벨이 울리는 시간
    bool isfind = false; // 전화벨을 들을 수 있는 시간을 찾았는가?

    for (int i = 1; ; i++) {
        btime = D * i;

        for (int j = 1; j <= N; j++) {
            int mtime = L * j + 5 * (j - 1); // 노래가 나오는 시간

            // 노래와 노래 사이의 조용한 구간에 btime이 포함되는지 확인
            if (btime >= mtime && btime < mtime + 5) {
                isfind = true;
                break;
            }
        }

        // 전화벨 듣는 시간을 찾았거나 앨범이 끝났을 때
        if (btime > N * L + (5 * (N - 1)) || isfind == true)
            break;
    }

    // 출력
    printf("%d\n", btime);

    return 0;
}