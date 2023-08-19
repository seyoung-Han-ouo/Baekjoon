#include <iostream>
using namespace std;

void quick_sort(int p, int r);
void swap(int i, int j);
void isSame();
int partition(int p, int r);

int N, cnt = 0;
int A[10001], B[10001];

// A[p..r]�� �������� �����Ѵ�.
void quick_sort(int p, int r) {
    if (p < r) {
        int q = partition(p, r); // ����

        quick_sort(p, q - 1);    // ���� �κ� �迭 ����
        quick_sort(q + 1, r);    // ������ �κ� �迭 ����
    }
}

// ���� ��ȯ
void swap(int i, int j) {
    cnt -= ((A[i] == B[i]) + (A[j] == B[j]));

    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;

    cnt += ((A[i] == B[i]) + (A[j] == B[j]));

    isSame();
}

// A�� B ��
void isSame() {
    if (cnt == N) {
        cout << "1\n";
        exit(0);
    }
}

int partition(int p, int r) {
    int x = A[r];   // ���ؿ���
    int i = p - 1;  // i�� x���� �۰ų� ���� ���ҵ��� ������

    // j�� ���� �������� ���� ���ҵ��� ���� ����, i�� ���� �� A[i], A[j] ��ȯ
    for (int j = p; j < r; j++)
        if (A[j] <= x) swap(++i, j);

    // i + 1�� r�� ���� �ٸ��� A[i + 1]�� A[r]�� ��ȯ
    if (i + 1 != r) swap(r, i + 1);

    return i + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) {
        cin >> B[i];

        if (A[i] == B[i]) cnt++;
    }

    isSame();

    quick_sort(0, N - 1);

    cout << "0\n";

    return 0;
}