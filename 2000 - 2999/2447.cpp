#include <iostream>
using namespace std;

void star(int N, int i, int j);

// 가운데를 제외한 모든 칸에 별을 그리는 함수
void star(int N, int i, int j) {
	if (i / N % 3 == 1 && j / N % 3 == 1)
		cout << " ";
	else if (N / 3 == 0 || N / 3 == 2)
		cout << "*";
	else
		star(N / 3, i, j);
}

int main() {
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			star(N, i, j);
		}
		cout << '\n';
	}
	
	return 0;
}