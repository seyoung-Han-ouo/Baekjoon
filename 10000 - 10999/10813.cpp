#include <iostream>
using namespace std;

int main() {
    int N, M; // �ٱ����� ���� N, ���� �ִ� ��� M
    scanf("%d %d", &N, &M);

    int arr[101];
    for (int i = 0; i <= N; i++) arr[i] = i;

    // a�� �ٱ��Ͽ� b�� �ٱ��Ͽ� ����ִ� ���� ��ȯ
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }

    // 1�� �ٱ��Ϻ��� N�� �ٱ��Ͽ� ����ִ� ���� ��ȣ ���
    for (int i = 1; i <= N; i++) printf("%d ", arr[i]);

    return 0;
}