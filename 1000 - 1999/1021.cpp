#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

vector<int> que;
int front = 0, rear = 0; // 맨 앞/ 맨 뒤에 있는 숫자
int N, M; // 큐의 크기 N, 뽑아내려고 하는 수의 개수 M

// 뽑아내야 하는 숫자의 현재 위치 찾기
int findNumLocate(int n) {
	int i = 0;
	for (i; i < N; i++) {
		if (que[i] == n)
			break;
	}

	return i;
}

// 왼쪽으로 n칸 이동
void moveLeft(int n) {
	for (int i = 0; i < n; i++) {
		int f = que.front();
		
		// 왼쪽으로 한 칸 이동했으므로 맨 앞에 있던 수가 맨 뒤에 위치한 숫자가 된다.
		que.push_back(f);
		que.erase(que.begin());
	}
}

// 오른쪽으로 n칸 이동
void moveRight(int n) {
	for (int i = 0; i < n; i++) {
		int b = que.back();

		// 오른쪽으로 한 칸 이동했으므로 맨 뒤에 있던 수가 맨 앞에 위치한 숫자가 된다.
		que.insert(que.begin(), b);
		que.pop_back();
	}
}

int main() {
	cin >> N >> M;

	// 큐에 요소 추가
	for (int i = 0; i < N; i++) {
		que.push_back(i + 1);
		rear++;
	}

	int count = 0; // 왼/오른쪽으로 숫자들을 이동시킨 횟수

	for (int i = 0; i < M; i++) {
		int locate; // 뽑으려는 숫자의 처음 위치
		cin >> locate;

		// 원하는 숫자가 맨 앞에 없으면 숫자를 뽑아내기 위해 칸을 이동시켜야 함
		if (front != locate) {
			int num = findNumLocate(locate);
			int left = abs(num - front);
			int right = abs(num - rear);

			// 더 적게 이동하는 방향으로 칸 이동
			if (left < right) {
				count += left;
				moveLeft(left);  // 왼쪽으로 이동
			}
			else { 
				count += right;
				moveRight(right); // 오른쪽으로 이동
			}
		}

		que.erase(que.begin()); // 첫 번째 원소를 뽑아낸다
		rear--;
	}

	// 출력
	printf("%d\n", count);

	return 0;
}