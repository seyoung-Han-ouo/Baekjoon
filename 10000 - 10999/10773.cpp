#include <iostream>
using namespace std;

struct stack {
	int top;
	char data[100001];
};

// ������Ÿ��
void init(stack* s);
void push(char c, stack* s);
char pop(stack* s);

// �ʱ�ȭ
void init(stack* s) {
	s->top = -1;
}

// ���� �Լ�
void push(char c, stack *s) {
	s->data[++(s->top)] = c;
}

// ���� �Լ�
char pop(stack* s) {
	return s->data[(s->top)--];
}

int main() {
	int K;
	cin >> K;
	
	stack stack;

	init(&stack); // �ʱ�ȭ

	int sum = 0; // ��

	for (int i = 0; i < K; i++) {
		int n;
		scanf("%d", &n);

		// 0�� �ԷµǸ� ���� �ֱ��� �� ����
		if (n == 0)
			sum -= pop(&stack);
		else {
			sum += n;
			push(n, &stack);
		}
	}

	// ���
	printf("%d\n", sum);

	return 0;
}