#include <iostream>
using namespace std;

int main() {
    int N, M; // �ٱ����� ���� N, ���� �ִ� ��� M
    scanf("%d %d", &N, &M);

    int arr[101] = { 0 };

    for (int i = 0; i < M; i++) {
        int start, end, num;
        scanf("%d %d %d", &start, &end, &num);

        for (int j = start - 1; j < end; j++)
            arr[j] = num;
    }

    // 1�� �ٱ��Ϻ��� N�� �ٱ��Ͽ� ����ִ� ���� ��ȣ ���
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);

    return 0;
}