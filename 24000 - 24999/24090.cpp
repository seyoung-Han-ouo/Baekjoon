#include <iostream>
using namespace std;

void quick_sort(int A[], int p, int r);
int partition(int A[], int p, int r);

int N, K; // �迭�� ũ�� N, ��ȯ Ƚ�� K
int cnt = 0; // ��ȯ Ƚ��

// A[p..r]�� �������� �����Ѵ�.
void quick_sort(int A[], int p, int r) {
    if (p < r) {
        int q = partition(A, p, r); // ����

        quick_sort(A, p, q - 1);    // ���� �κ� �迭 ����
        quick_sort(A, q + 1, r);    // ������ �κ� �迭 ����
    }
}

int partition(int A[], int p, int r) {
    int x = A[r]; // ���ؿ���
    int i = p - 1; // i�� x���� �۰ų� ���� ���ҵ��� ������

    // j�� ���� �������� ���� ���ҵ��� ���� ����
    for (int j = p; j < r; j++) {
        // i�� ���� �� A[i], A[j] ��ȯ
        if (A[j] <= x) {
            int tmp = A[++i];
            A[i] = A[j];
            A[j] = tmp;

            // K ��° ��ȯ
            if (++cnt == K) {
                printf("%d %d\n", min(A[i], A[j]), max(A[i], A[j]));
                exit(0);
            }
        }
    }

    // i + 1�� r�� ���� �ٸ��� A[i + 1]�� A[r]�� ��ȯ
    if (i + 1 != r) {
        int tmp = A[r];
        A[r] = A[i + 1];
        A[i + 1] = tmp;
        
        // K ��° ��ȯ
        if (++cnt == K) {
            printf("%d %d\n", min(A[r], A[i + 1]), max(A[r], A[i + 1]));
            exit(0);
        }
    }

    return i + 1;
}

int main() {
    scanf("%d %d", &N, &K);

    int* A = new int[N];

    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    quick_sort(A, 0, N - 1);

    printf("-1\n");

	return 0;
}