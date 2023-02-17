#include <iostream>
#include <vector>
using namespace std;

int insertion_sort(int N);

vector <int> A(10001);
vector <int> B(10001);

// ���� ����
int insertion_sort(int N) {
    //A[]�� �������� �����Ѵ�.
    for (int i = 1; i < N; i++) {
        int loc;
        int newItem = A[i];

        // �� �������� A[1..i - 1]�� �̹� ���ĵǾ� �ִ� ����
        for (loc = i - 1; loc >= 0 && newItem < A[loc]; loc--) {
            A[loc + 1] = A[loc];

            //  �迭 A�� �迭 B�� ���� ���
            if (A == B) return 1;
        }

        if (loc + 1 != i) {
            A[loc + 1] = newItem;

            //  �迭 A�� �迭 B�� ���� ���
            if (A == B) return 1;
        }
    }

    return 0;
}

int main() {
	int N; //  �迭�� ũ�� N
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

    for (int i = 0; i < N; i++)
        scanf("%d", &B[i]);

    // ���
    printf("%d\n", insertion_sort(N));

	return 0;
}