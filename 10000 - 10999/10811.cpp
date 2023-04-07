#include <iostream>
using namespace std;

int main() {
    int N, M; // �ٱ����� ���� N, �ٱ����� ������ �������� ����� ��� M
    scanf("%d %d", &N, &M);

    int arr[101];
    for (int i = 0; i <= N; i++) arr[i] = i;

    // a��° �ٱ��Ϻ��� b��° �ٱ����� ������ ��������
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        for (int j = b; j > a; j--) {
            int tmp = arr[j];
            arr[j] = arr[a];
            arr[a++] = tmp;
        }
    }

    // ���
    for (int i = 1; i <= N; i++) printf("%d ", arr[i]);

    return 0;
}