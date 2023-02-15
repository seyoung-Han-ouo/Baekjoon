#include <iostream>
using namespace std;

int insertion_sort(int N, int K, int A[]);

// ���� ����
int insertion_sort(int N, int K, int A[]) {
    int count = 0; // ���� Ƚ��

    //A[]�� �������� �����Ѵ�.
    for (int i = 1; i < N; i++) {
        int loc; 
        int newItem = A[i];

        // �� �������� A[1..i - 1]�� �̹� ���ĵǾ� �ִ� ����
        for (loc = i - 1; loc >= 0 && newItem < A[loc]; loc--) {
            A[loc + 1] = A[loc];
            count++;

            // K ��° ����
            if (count == K) return A[loc + 1];
        }

        if (loc + 1 != i) {
            A[loc + 1] = newItem;
            count++;

            // K ��° ����
            if (count == K) return A[loc + 1];
        }
    }

    return -1;
}

int main() {
	int N, K; //  �迭�� ũ�� N, ���� Ƚ�� K
	scanf("%d %d", &N, &K);

    int* A = new int[N];

	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

    // ���
	cout << insertion_sort(N, K, A) << endl;

	return 0;
}