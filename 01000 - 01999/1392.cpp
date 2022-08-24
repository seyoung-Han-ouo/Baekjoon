#include <iostream>
using namespace std;

int main() {
	// 악보의 수 N, 질문의 개수 Q
	int N, Q;
	cin >> N >> Q;

	// 각 악보가 끝나는 시간
	int* time = new int[N];

	// 각 악보가 끝나는 시간구하기
	for (int i = 0; i < N; i++) {
		int n;
		scanf("%d", &n);

		if (i == 0)
			time[i] = n - 1;
		else
			time[i] = time[i - 1] + n;
	}

	// 해당 시간에 부르는 악보 번호 찾기
	for (int i = 0; i < Q; i++) {
		int q;
		scanf("%d", &q);

		for (int j = 0; j < N; j++) {
			if (q <= time[j]) {
				printf("%d\n", j + 1);
				break;
			}
		}
	}

	return 0;
}