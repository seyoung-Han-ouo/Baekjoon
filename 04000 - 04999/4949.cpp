#include <iostream>
#include <string>
using namespace std;

struct stack {
	int top;
	char data[101];
};

// 초기화
void init(stack* s) {
	s->top = -1;
}

// 스택이 비어있는지 확인
bool isEmpty(stack* s) {
	return s->top == -1;
}

// 삽입 함수
void push(char c, stack *s) {
	s->data[++(s->top)] = c;
}

// 삭제 함수
char pop(stack* s) {
	return s->data[(s->top)--];
}

// 맨 위의 요소 꺼내오기
char peek(stack* s) {
	return s->data[s->top];
}

int main() {
	while (true) {
		stack stack;
		string s;
		getline(cin, s);

		init(&stack); // 초기화

		//.만 입력하면 반복 종료
		if (s == ".") break;

		// 문자열이 균형을 이루고 있는 지 확인한다.
		for (int i = 0; i < s.length(); i++) {
			char c = s[i];
			
			if (c == '(' || c == '[')
				push(c, &stack);
			else {
				switch (c) {
				case ')':
					if (peek(&stack) == '(')
						pop(&stack);
					else
						push(c, &stack);
					break;

				case ']':
					if (peek(&stack) == '[')
						pop(&stack);
					else
						push(c, &stack);
					break;
				}
			}
		}

		// 출력
		if (isEmpty(&stack))
			printf("yes\n");
		else
			printf("no\n");
	}

	return 0;
}