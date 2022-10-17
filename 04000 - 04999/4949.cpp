#include <iostream>
#include <string>
using namespace std;

struct stack {
	int top;
	char data[101];
};

// �ʱ�ȭ
void init(stack* s) {
	s->top = -1;
}

// ������ ����ִ��� Ȯ��
bool isEmpty(stack* s) {
	return s->top == -1;
}

// ���� �Լ�
void push(char c, stack *s) {
	s->data[++(s->top)] = c;
}

// ���� �Լ�
char pop(stack* s) {
	return s->data[(s->top)--];
}

// �� ���� ��� ��������
char peek(stack* s) {
	return s->data[s->top];
}

int main() {
	while (true) {
		stack stack;
		string s;
		getline(cin, s);

		init(&stack); // �ʱ�ȭ

		//.�� �Է��ϸ� �ݺ� ����
		if (s == ".") break;

		// ���ڿ��� ������ �̷�� �ִ� �� Ȯ���Ѵ�.
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

		// ���
		if (isEmpty(&stack))
			printf("yes\n");
		else
			printf("no\n");
	}

	return 0;
}