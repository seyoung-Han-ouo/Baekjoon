#include <iostream>
using namespace std;

struct stack {
	char data[51];
	int top;
};

// 초기화
void init(stack* s) {
	s->top = -1;
}

// 삽입 함수
void push(stack* s, int n) {
	s->data[++(s->top)] = n;
}

// 삭제 함수
char pop(stack* s) {
	return s->data[(s->top)--];
}

// 스택이 비어있는지 확인
bool isEmpty(stack* s) {
	return (s->top == -1);
}

// 맨 위의 요소 꺼내오기
char peek(stack* s) {
	return s->data[s->top];
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		stack stack;
		string s;
		cin >> s;

		init(&stack); // 초기화

		if (s.length() % 2 == 0) { // 문자열의 길이가 짝수일 때
			// 올바른 괄호 문자열인지 알아본다.
			for (int j = 0; j < s.length(); j++) {
				char c = s[j];

				switch (c) {
				case '(':
					push(&stack, c);
					break;

				case ')':
					if (peek(&stack) == '(')
						pop(&stack);
					else
						push(&stack, c);
					break;
				}
			}
		}

		// 출력
		if (isEmpty(&stack) && s.length() % 2 == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}