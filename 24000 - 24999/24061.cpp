#include <iostream>
using namespace std;

void merge(int A[], int p, int q, int r);
void merge_sort(int A[], int p, int r);

int* A, * tmp;
int N, K; // �迭 A�� ũ�� N, ���� Ƚ�� K
int cnt = 0; // ���� Ƚ��
bool isCntK = false;

// A[p..q]�� A[q + 1..r]�� �����Ͽ� A[p..r]�� �������� ���ĵ� ���·� �����.
// A[p..q]�� A[q + 1..r]�� �̹� ������������ ���ĵǾ� �ִ�.
void merge(int A[], int p, int q, int r) {
    int i = p;
    int j = q + 1;
    int t = 1;

    while (i <= q && j <= r) {
        if (A[i] <= A[j])
            tmp[t++] = A[i++];
        else
            tmp[t++] = A[j++];
    }

    // ���� �迭 �κ��� ���� ���
    while (i <= q)
        tmp[t++] = A[i++];

    // ������ �迭 �κ��� ���� ���
    while (j <= r)
        tmp[t++] = A[j++];

    i = p;
    t = 1;

    // ����� A[p..r]�� ����
    while (i <= r) {
        A[i++] = tmp[t++];
        cnt++;

        // K ��° ����
        if (cnt == K) {
            isCntK = true;

            // ���
            for (int i = 0; i < N; i++)
                printf("%d ", A[i]);

            break;
        }
    }
}

void merge_sort(int A[], int p, int r) {
    if (isCntK) return;

    //A[p..r]�� �������� �����Ѵ�.
    if (p < r) {
        int q = (p + r) / 2;        // q�� p, r�� �߰� ����

        merge_sort(A, p, q);        // ���ݺ� ����
        merge_sort(A, q + 1, r);    // �Ĺݺ� ����
        merge(A, p, q, r);          // ����
    }
}


int main() {
    scanf("%d %d", &N, &K);

    A = new int[N + 1];
    tmp = new int[N + 1];

    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    merge_sort(A, 0, N - 1);

    if (!isCntK) printf("-1\n");

    delete[] A;
    delete[] tmp;

    return 0;
}