#include <iostream>
using namespace std;

int main() {
    int N, M; // 바구니의 개수 N, 바구니의 순서를 역순으로 만드는 방법 M
    scanf("%d %d", &N, &M);

    int arr[101];
    for (int i = 0; i <= N; i++) arr[i] = i;

    // a번째 바구니부터 b번째 바구니의 순서를 역순으로
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        for (int j = b; j > a; j--) {
            int tmp = arr[j];
            arr[j] = arr[a];
            arr[a++] = tmp;
        }
    }

    // 출력
    for (int i = 1; i <= N; i++) printf("%d ", arr[i]);

    return 0;
}