#include <iostream>
using namespace std;

#define MAXSIZE 500001

struct queueType {
	int front; // 전단 : 삭제가 일어나는 곳, 큐의 첫 번째 요소
	int rear; // 후단 : 삽입이 일어나는 곳, 큐의 마지막 요소

	int data[MAXSIZE];
};

queueType card;

// 큐 초기화
void init(queueType* q) {
	q->front = 0;
	q->rear = 0;
}

// 삽입 함수
void enqueue(queueType* q, int item) {
	q->rear = (q->rear + 1) % MAXSIZE;
	q->data[q->rear] = item;
}

// 삭제 함수 (삭제한 숫자를 return한다.)
int dequeue(queueType* q) {
	q->front = (q->front + 1) % MAXSIZE;

	return q->data[q->front];
}

int main() {
	int N;
	cin >> N;

	init(&card); // 큐를 초기화한다.

	// N개의 카드
	for (int i = 0; i < N; i++)
		enqueue(&card, i + 1);

	for (int i = 0; ; i++) {
		// 마지막으로 남은 카드 출력
		if (N == 1) {
			printf("%d", dequeue(&card));
			break;
		}

		if (i % 2 == 0) { // 카드를 버린다.
			N--;
			dequeue(&card);
		}
		else // 카드를 제일 아래로 옮긴다.
			enqueue(&card, dequeue(&card));
	}

	return 0;
}