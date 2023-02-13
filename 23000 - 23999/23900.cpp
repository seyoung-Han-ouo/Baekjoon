#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> A(500001);
vector<int> B(500001);
unordered_map <int, int> m;

// 선택 정렬
int selection_sort(int N) {
	if (A == B) return 1;

	vector<int> arr(A);
	sort(arr.begin(), arr.begin() + N);

	//A[1..N]을 오름차순 정렬한다.
	for (int i = N - 1; i > 0; i--) {
		int big = m[arr[i]]; // 가장 큰 수의 위치

		// 다르면 교환이 발생
		if (i != big) {
			int tmp = A[i];
			A[i] = A[big];
			A[big] = tmp;

			m[A[big]] = big;

			// 배열 A가 배열 B와 같은 경우
			if (A == B) return 1;
		}
	}

	return 0;
}

int main() {
	int N; //  배열의 크기 N
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