#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> A(500001);
vector<int> B(500001);
unordered_map <int, int> m;

// ���� ����
int selection_sort(int N) {
	if (A == B) return 1;

	vector<int> arr(A);
	sort(arr.begin(), arr.begin() + N);

	//A[1..N]�� �������� �����Ѵ�.
	for (int i = N - 1; i > 0; i--) {
		int big = m[arr[i]]; // ���� ū ���� ��ġ

		// �ٸ��� ��ȯ�� �߻�
		if (i != big) {
			int tmp = A[i];
			A[i] = A[big];
			A[big] = tmp;

			m[A[big]] = big;

			// �迭 A�� �迭 B�� ���� ���
			if (A == B) return 1;
		}
	}

	return 0;
}

int main() {
	int N; //  �迭�� ũ�� N
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		m.insert(make_pair(A[i], i));
	}

	for (int i = 0; i < N; i++)
		scanf("%d", &B[i]);

	cout << selection_sort(N) << endl;

	return 0;
}