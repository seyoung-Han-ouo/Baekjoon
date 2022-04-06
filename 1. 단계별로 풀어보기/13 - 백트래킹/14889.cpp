#include <iostream>
using namespace std;

int N; // 수의 개수
int num[20][20]; // 숫자 저장
bool team[20] = { false };

int start[10];
int link[10];

int sum = 1000000000; // 차이

// 스타트 팀과 링크 팀의 능력치의 차이의 최솟값 찾기
void Team(int inx, int cnt) {
	if (cnt == N / 2) {
		int result1 = 0;
		int result2 = 0;

		// 각팀을 2개의 배열에 저장
		int idx1 = 0, idx2 = 0;
		for (int i = 0; i < N; i++) {
			if (team[i])
				start[idx1++] = i;
			else
				link[idx2++] = i;
		}

		// 각팀의 능력치 합
		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < N / 2; j++) {
				result1 += num[start[i]][start[j]];
				result2 += num[link[i]][link[j]];
			}
		}

		// 팀의 능력치 차이가 최소인지를 확인
		if (abs(result1 - result2) < sum)
			sum = abs(result1 - result2);
	}
	// 팀을 나누는 경우의 수 찾기
	else {
		for (int i = inx; i < N; i++) {
			if (!team[i]) {
				team[i] = true;

				Team(i, cnt + 1);

				team[i] = false;
			}
		}
	}
}

int main() {
	// 입력
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			scanf("%d", &num[i][j]);
	}

	// 스타트 팀과 링크 팀의 능력치의 차이의 최솟값 찾기
	Team(0, 0);

	// 출력
	printf("%d", sum);

	return 0;
}