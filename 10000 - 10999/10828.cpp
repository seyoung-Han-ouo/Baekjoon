#include <iostream>
using namespace std;

struct stack {
	int top = -1;
	int element[10001] = {};
};

stack s;

// 정수를 스택에 넣는 연산
void push(int n) {
	s.element[++s.top] = n;
}

// 스택이 비어있으면 1, 아니면 0을 출력
int empty() {
	if (s.top == -1)
		return 1;
	else
		return 0;
}

// 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력
int pop() {
	if (empty())
		return -1;
	else
		return s.element[s.top--];
}

// 스택에 들어있는 정수의 개수를 출력
int size() {
	return s.top + 1;
}

// 스택의 가장 위에 있는 정수를 출력
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

			// 출력
			printf("%d\n", num);
		}
	}

	return 0;
}