#include <iostream>
using namespace std;

int main() {
    int N, M; // 바구니의 개수 N, 공을 넣는 방법 M
    scanf("%d %d", &N, &M);

    int arr[101] = { 0 };

    for (int i = 0; i < M; i++) {
        int start, end, num;
        scanf("%d %d %d", &start, &end, &num);

        for (int j = start - 1; j < end; j++)
            arr[j] = num;
    }

    // 1번 바구니부터 N번 바구니에 들어있는 공의 번호 출력
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);

    return 0;
}