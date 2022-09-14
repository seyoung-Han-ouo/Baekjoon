#include <iostream>
using namespace std;

struct stack {
	char data[51];
	int top;
};

// �ʱ�ȭ
void init(stack* s) {
	s->top = -1;
}

// ���� �Լ�
void push(stack* s, int n) {
	s->data[++(s->top)] = n;
}

// ���� �Լ�
char pop(stack* s) {
	return s->data[(s->top)--];
}

// ������ ����ִ��� Ȯ��
bool isEmpty(stack* s) {
	return (s->top == -1);
}

// �� ���� ��� ��������
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

		init(&stack); // �ʱ�ȭ

		if (s.length() % 2 == 0) { // ���ڿ��� ���̰� ¦���� ��
			// �ùٸ� ��ȣ ���ڿ����� �˾ƺ���.
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

		// ���
		if (isEmpty(&stack) && s.length() % 2 == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}