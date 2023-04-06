#include <iostream>
using namespace std;

int main() {
    int N, M; // 바구니의 개수 N, 공을 넣는 방법 M
    scanf("%d %d", &N, &M);

    int arr[101];
    for (int i = 0; i <= N; i++) arr[i] = i;

    // a번 바구니와 b번 바구니에 들어있는 공을 교환
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }

    // 1번 바구니부터 N번 바구니에 들어있는 공의 번호 출력
    for (int i = 1; i <= N; i++) printf("%d ", arr[i]);

    return 0;
}