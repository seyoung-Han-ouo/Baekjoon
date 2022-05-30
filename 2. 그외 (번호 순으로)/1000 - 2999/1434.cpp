#include <iostream>
using namespace std;

int main() {
	int N, M; // 박스의 개수 N, 책의 개수 M
	cin >> N >> M;

	int* box = new int[N]; // 박스의 용량

	// 박스의 용량 입력
	for (int i = 0; i < N; i++)
		scanf("%d", &box[i]);

	// 책 넣기
	for (int i = 0; i < M; i++) {
		int book;
		scanf("%d", &book);

		for (int j = 0; j < N; j++) {
			if (book <= box[j]) {
				box[j] -= book;
				break;
			}
		}
	}
		
	// 박스의 낭비된 용량
	int waste = 0;
	for (int i = 0; i < N; i++)
		waste += box[i];

	// 출력
	cout << waste << endl;

	return 0;
}