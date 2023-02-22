#include <iostream>
#include <vector>
using namespace std;

bool sameIdx();
void print(int n);
void merge(int p, int q, int r);
void merge_sort(int p, int r);

int N; // �迭 A�� ũ�� N
int idx = -1;

vector <int> A(500001);
vector <int> B(500001);
vector <int> tmp(500001);

// �迭 A�� �迭 B ��
bool sameIdx() {
    for (int i = idx; i < N; i++) {
        if (i == -1) i = 0;

        if (A[i] != B[i]) {
            idx = i - 1;
            return false;
        }
    }

    return true;
}

// 1, �ƴϸ� 0�� ���
void print(int n) {
    printf("%d\n", n);
    exit(0);
}

// A[p..q]�� A[q + 1..r]�� �����Ͽ� A[p..r]�� �������� ���ĵ� ���·� �����.
// A[p..q]�� A[q + 1..r]�� �̹� ������������ ���ĵǾ� �ִ�.
void merge(int p, int q, int r) {
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
        if (A[i] != tmp[t]) {
            // �迭 A�� �迭 B�� ���� ��찡 ����
            if (i <= idx) print(0);

            A[i++] = tmp[t++];

            // �迭 A�� �迭 B�� ���� ���
            if (sameIdx()) print(1);
        }
        else
            A[i++] = tmp[t++];
    }
}

void merge_sort(int p, int r) {
    if (sameIdx()) print(1);

    //A[p..r]�� �������� �����Ѵ�.
    if (p < r) {
        int q = (p + r) / 2;    // q�� p, r�� �߰� ����

        merge_sort(p, q);       // ���ݺ� ����
        merge_sort(q + 1, r);   // �Ĺݺ� ����
        merge(p, q, r);         // ����
    }
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    for (int i = 0; i < N; i++)
        scanf("%d", &B[i]);

    merge_sort(0, N - 1);

    printf("0\n");

    return 0;
}