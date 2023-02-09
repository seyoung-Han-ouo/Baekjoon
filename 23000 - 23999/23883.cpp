#include <iostream>
#include <map>
using namespace std;

int selection_sort(int N, int K);

map <int, int> m;
int A[500001];

// ���� ���� 
int selection_sort(int N, int K) {
	int count = 0; // ��ȯ Ƚ��
	int idx = N - 1;

	map <int, int>::reverse_iterator it = m.rbegin();

	for (it = m.rbegin(); it != m.rend(); ++it) {
		int big = it->second; // A[]�� ���� ū ��

		// last�� big�� ���� �ٸ��� ��ȯ�� �߻��Ѵ�.
		if (big != idx) {
			int tmp = A[idx];
			A[idx] = it->first;
			A[big] = tmp;

			// �� ������ ���� �ε��� ��ġ
			it->second = idx;
			map<int, int>::iterator find = m.find(tmp);
			find->second = big;

			count++;
		}

		// K ��° ��ȯ
		if (count == K) {
			printf("%d %d\n", A[big], A[idx]); // ���

			return 0;
		}

		idx--;
	}

	// ���
	printf("-1\n");

	return 0;
}

int main() {
	int N, K; //  �迭 A�� ũ�� N, ��ȯ Ƚ�� K
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		m.insert(map<int, int>::value_type(A[i], i));
	}

	selection_sort(N, K);

	return 0;
}