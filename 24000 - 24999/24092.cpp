#include <iostream>
#include <vector>
using namespace std;

bool isSame();
void print(int n);
void quick_sort(int p, int r);
int partition(int p, int r);

int N; // �迭�� ũ�� N
int sameIdx = -1; // �� �迭�� ���� �ε���
vector <int> A(10001);
vector <int> B(10001);

// �� �迭�� ������?
bool isSame() {
    if (sameIdx < 0) sameIdx = 0;

    for (int i = sameIdx; i < N; i++) {
        if (A[i] != B[i]) {
            sameIdx = i - 1;
            return false;
        }
    }

    return true;
}

// ���
void print(int n) {
    printf("%d\n" , n);
    exit(0);
}

// A[p..r]�� �������� �����Ѵ�.
void quick_sort(int p, int r) {
    if (p < r) {
        int q = partition(p, r); // ����

        quick_sort(p, q - 1);    // ���� �κ� �迭 ����
        quick_sort(q + 1, r);    // ������ �κ� �迭 ����
    }
}

int partition(int p, int r) {
    int x = A[r]; // ���ؿ���
    int i = p - 1; // i�� x���� �۰ų� ���� ���ҵ��� ������

    // j�� ���� �������� ���� ���ҵ��� ���� ����
    for (int j = p; j < r; j++) {
        // i�� ���� �� A[i], A[j] ��ȯ
        if (A[j] <= x) {
            int tmp = A[++i];
            A[i] = A[j];
            A[j] = tmp;

            // �迭 A�� �迭 B�� ���� ���
            if (A[j] == B[j] || A[i] == B[i])
                if (isSame()) print(1);
        }
    }

    // i + 1�� r�� ���� �ٸ��� A[i + 1]�� A[r]�� ��ȯ
    if (i + 1 != r) {
        int tmp = A[r];
        A[r] = A[i + 1];
        A[i + 1] = tmp;

        // �迭 A�� �迭 B�� ���� ���
        if (A[i + 1] == B[i + 1] || A[r] == B[r])
            if (isSame()) print(1);
    }

    return i + 1;
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    for (int i = 0; i < N; i++)
        scanf("%d", &B[i]);

    // �迭 A�� �迭 B�� ���� ���
    if (A == B) print(1);

    quick_sort(0, N - 1);

    printf("0\n");

	return 0;
}