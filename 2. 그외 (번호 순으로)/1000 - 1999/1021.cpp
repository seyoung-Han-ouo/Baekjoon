#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

vector<int> que;
int front = 0, rear = 0; // �� ��/ �� �ڿ� �ִ� ����
int N, M; // ť�� ũ�� N, �̾Ƴ����� �ϴ� ���� ���� M

// �̾Ƴ��� �ϴ� ������ ���� ��ġ ã��
int findNumLocate(int n) {
	int i = 0;
	for (i; i < N; i++) {
		if (que[i] == n)
			break;
	}

	return i;
}

// �������� nĭ �̵�
void moveLeft(int n) {
	for (int i = 0; i < n; i++) {
		int f = que.front();
		
		// �������� �� ĭ �̵������Ƿ� �� �տ� �ִ� ���� �� �ڿ� ��ġ�� ���ڰ� �ȴ�.
		que.push_back(f);
		que.erase(que.begin());
	}
}

// ���������� nĭ �̵�
void moveRight(int n) {
	for (int i = 0; i < n; i++) {
		int b = que.back();

		// ���������� �� ĭ �̵������Ƿ� �� �ڿ� �ִ� ���� �� �տ� ��ġ�� ���ڰ� �ȴ�.
		que.insert(que.begin(), b);
		que.pop_back();
	}
}

int main() {
	cin >> N >> M;

	// ť�� ��� �߰�
	for (int i = 0; i < N; i++) {
		que.push_back(i + 1);
		rear++;
	}

	int count = 0; // ��/���������� ���ڵ��� �̵���Ų Ƚ��

	for (int i = 0; i < M; i++) {
		int locate; // �������� ������ ó�� ��ġ
		cin >> locate;

		// ���ϴ� ���ڰ� �� �տ� ������ ���ڸ� �̾Ƴ��� ���� ĭ�� �̵����Ѿ� ��
		if (front != locate) {
			int num = findNumLocate(locate);
			int left = abs(num - front);
			int right = abs(num - rear);

			// �� ���� �̵��ϴ� �������� ĭ �̵�
			if (left < right) {
				count += left;
				moveLeft(left);  // �������� �̵�
			}
			else { 
				count += right;
				moveRight(right); // ���������� �̵�
			}
		}

		que.erase(que.begin()); // ù ��° ���Ҹ� �̾Ƴ���
		rear--;
	}

	// ���
	printf("%d\n", count);

	return 0;
}