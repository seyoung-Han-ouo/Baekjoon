#include <iostream>
using namespace std;

int main() {
    int N, M; // 수의 개수 N, 합을 구해야 하는 횟수 M
    scanf("%d %d", &N, &M);

    int* arr = new int[N + 1];
    arr[0] = 0;

    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);

        arr[i] += arr[i - 1];
    }

    // a번째 수부터 b번째 수까지 합을 출력
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        printf("%d\n", arr[b] - arr[a - 1]);
    }

    return 0;
}