#include <iostream>
using namespace std;

int N, M;
int arr[1001];
int frd[1001];
bool check[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> arr[i];

    for (int i = 0; i < M; i++) {
        cin >> frd[i];

        // 친구의 대기 순서 찾기
        for (int j = 0; j < N; j++) {
            if (arr[j] == frd[i]) {
                // 다른 사람보다 먼저 들어갈 수 있는 범위에 속했을 때
                if (j < M) {
                    frd[i] = -1;
                    check[j] = true;
                }

                break;
            }
        }
    }

    int cnt = 0;

    for (int i = 0; i < M; i++) {
        // 순서를 바꿀 필요가 없을 때
        if (frd[i] == -1) continue;

        // 순서 바꾸기
        for (int j = 0; j < N; j++) {
            if (!check[j]) {
                check[j] = true;
                cnt++;

                break;
            }
        }
    }

    // 출력
    cout << cnt << '\n';

    return 0;
}