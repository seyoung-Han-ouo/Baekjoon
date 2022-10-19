#include <iostream>
using namespace std;

struct stack {
	int top;
	char data[100001];
};

// 프로토타입
void init(stack* s);
void push(char c, stack* s);
char pop(stack* s);

// 초기화
void init(stack* s) {
	s->top = -1;
}

// 삽입 함수
void push(char c, stack *s) {
	s->data[++(s->top)] = c;
}

// 삭제 함수
char pop(stack* s) {
	return s->data[(s->top)--];
}

int main() {
	int K;
	cin >> K;
	
	stack stack;

	init(&stack); // 초기화

	int sum = 0; // 합

	for (int i = 0; i < K; i++) {
		int n;
		scanf("%d", &n);

		// 0이 입력되면 가장 최근의 수 삭제
		if (n == 0)
			sum -= pop(&stack);
		else {
			sum += n;
			push(n, &stack);
		}
	}

	// 출력
	printf("%d\n", sum);

	return 0;
}