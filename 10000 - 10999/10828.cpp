#include <iostream>
using namespace std;

struct stack {
	int top = -1;
	int element[10001] = {};
};

stack s;

// ������ ���ÿ� �ִ� ����
void push(int n) {
	s.element[++s.top] = n;
}

// ������ ��������� 1, �ƴϸ� 0�� ���
int empty() {
	if (s.top == -1)
		return 1;
	else
		return 0;
}

// ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ���
int pop() {
	if (empty())
		return -1;
	else
		return s.element[s.top--];
}

// ���ÿ� ����ִ� ������ ������ ���
int size() {
	return s.top + 1;
}

// ������ ���� ���� �ִ� ������ ���
int top() {
	return s.element[s.top];
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		int num;

		if (s == "push") {
			cin >> num;
			push(num);
		}
		else {
			if (s == "pop")
				num = pop();
			else if (s == "size")
				num = size();
			else if (s == "empty")
				num = empty();
			else
				num = top();

			// ���
			printf("%d\n", num);
		}
	}

	return 0;
}