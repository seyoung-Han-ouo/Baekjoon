#include <iostream>
using namespace std;

struct queue {
    int arr[5001];
    int front, rear;
};

int N, K; // N명의 사람, K번째 사람
int numArr[5001];
queue q;

void init();
void enqueue(int n);
int dequeue();
void print();

// 큐 초기화
void init() {
    q.front = q.rear = 0;

    for (int i = 1; i <= N; i++) enqueue(i);
}

// 삽입 함수
void enqueue(int n) {
    q.rear = (q.rear + 1) % N;
    q.arr[q.rear] = n;
}

// 삭제 함수
int dequeue() {
    q.front = (q.front + 1) % N;

    return q.arr[q.front];
}

// 출력
void print() {
    printf("<%d", numArr[0]);
    for (int i = 1; i < N; i++) printf(", %d", numArr[i]);
    printf(">\n");
}

int main() {
    scanf("%d %d", &N, &K);

    init();

    // 순서대로 K번째 사람을 제거
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K - 1; j++) enqueue(dequeue());

        numArr[i] = dequeue();
    }

    print();

    return 0;
}