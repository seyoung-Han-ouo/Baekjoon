#include <iostream>
#include <queue>
using namespace std;

int main() {
	int T; // 테스트케이스의 수
	cin >> T;

	for (int i = 0; i < T; i++) {
		priority_queue<int> pq; // 우선순위큐
		queue<pair<int, int>> q;
		int N, M; // 문서의 개수 N, 원하는 문서의 현재 위치 M,

		scanf("%d %d", &N, &M);

		// 큐에 데이터 입력
		for (int j = 0; j < N; j++) {
			int data;
			scanf("%d", &data);
			pq.push(data);
			q.push({ j, data });
		}

		int count = 0; // 인쇄 번째
		while (true) {
			if (pq.top() == q.front().second) {
				count++;

				// 원하는 문서가 인쇄되면 반복 종료
				if (q.front().first == M) break;
				else { 
					pq.pop();
					q.pop();
				}
			}
			else {
				q.push({ q.front().first, q.front().second });
				q.pop();
			}
		}

		// 출력
		printf("%d\n", count);
	}

	return 0;
}