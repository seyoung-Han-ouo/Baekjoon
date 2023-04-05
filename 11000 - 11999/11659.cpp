#include <iostream>
using namespace std;

int main() {
    int N, M; // ���� ���� N, ���� ���ؾ� �ϴ� Ƚ�� M
    scanf("%d %d", &N, &M);

    int* arr = new int[N + 1];
    arr[0] = 0;

    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);

        arr[i] += arr[i - 1];
    }

    // a��° ������ b��° ������ ���� ���
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        printf("%d\n", arr[b] - arr[a - 1]);
    }

    return 0;
}