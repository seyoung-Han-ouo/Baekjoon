#include <iostream>
using namespace std;

#define MAXSIZE 500001

struct queueType {
	int front; // ���� : ������ �Ͼ�� ��, ť�� ù ��° ���
	int rear; // �Ĵ� : ������ �Ͼ�� ��, ť�� ������ ���

	int data[MAXSIZE];
};

queueType card;

// ť �ʱ�ȭ
void init(queueType* q) {
	q->front = 0;
	q->rear = 0;
}

// ���� �Լ�
void enqueue(queueType* q, int item) {
	q->rear = (q->rear + 1) % MAXSIZE;
	q->data[q->rear] = item;
}

// ���� �Լ� (������ ���ڸ� return�Ѵ�.)
int dequeue(queueType* q) {
	q->front = (q->front + 1) % MAXSIZE;

	return q->data[q->front];
}

int main() {
	int N;
	cin >> N;

	init(&card); // ť�� �ʱ�ȭ�Ѵ�.

	// N���� ī��
	for (int i = 0; i < N; i++)
		enqueue(&card, i + 1);

	for (int i = 0; ; i++) {
		// ���������� ���� ī�� ���
		if (N == 1) {
			printf("%d", dequeue(&card));
			break;
		}

		if (i % 2 == 0) { // ī�带 ������.
			N--;
			dequeue(&card);
		}
		else // ī�带 ���� �Ʒ��� �ű��.
			enqueue(&card, dequeue(&card));
	}

	return 0;
}