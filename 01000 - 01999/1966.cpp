#include <iostream>
#include <queue>
using namespace std;

int main() {
	int T; // �׽�Ʈ���̽��� ��
	cin >> T;

	for (int i = 0; i < T; i++) {
		priority_queue<int> pq; // �켱����ť
		queue<pair<int, int>> q;
		int N, M; // ������ ���� N, ���ϴ� ������ ���� ��ġ M,

		scanf("%d %d", &N, &M);

		// ť�� ������ �Է�
		for (int j = 0; j < N; j++) {
			int data;
			scanf("%d", &data);
			pq.push(data);
			q.push({ j, data });
		}

		int count = 0; // �μ� ��°
		while (true) {
			if (pq.top() == q.front().second) {
				count++;

				// ���ϴ� ������ �μ�Ǹ� �ݺ� ����
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

		// ���
		printf("%d\n", count);
	}

	return 0;
}