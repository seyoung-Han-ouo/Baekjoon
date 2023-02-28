#include <iostream>
using namespace std;

void print(int A[]);
void heap_sort(int A[]);
void build_min_heap(int A[], int n);
void heapify(int A[], int k, int n);

int N, K; // 배열의 크기 N, 교환 횟수 K
int cnt = 0;

// K 번째 교환되는 두 개의 수를 작은 수부터 한 줄에 출력
void print(int A[]) {
    for (int i = 1; i < N + 1; i++)
        printf("%d ", A[i]);
    exit(0);
}

void heap_sort(int A[]) {
    // A[1..n]을 정렬한다.
    build_min_heap(A, N);

    for (int i = N; i > 1; i--) {
        int tmp = A[1];
        A[1] = A[i];
        A[i] = tmp;
        
        if (++cnt == K) print(A);

        heapify(A, 1, i - 1);
    }
}

void build_min_heap(int A[], int n) {
    for (int i = (n / 2); i > 0; i--)
        heapify(A, i, n);
}

// A[k]를 루트로 하는 트리를 최소 힙 성질을 만족하도록 수정한다.
// A[k]의 두 자식을 루트로 하는 서브 트리는 최소 힙 성질을 만족하고 있다.
// n은 배열 A의 전체 크기이며 최대 인덱스를 나타낸다.
void heapify(int A[], int h, int n) {
    int left = 2 * h;
    int right = 2 * h + 1;
    int smaller;

    if (right <= n) {
        if (A[left] < A[right]) smaller = left;
        else smaller = right;
    }
    else if (left <= n) smaller = left;
    else return;

    //최소 힙 성질을 만족하지 못하는 경우 재귀적으로 수정한다.
    if (A[smaller] < A[h]) {
        int tmp = A[h];
        A[h] = A[smaller];
        A[smaller] = tmp;

        if (++cnt == K) print(A);

        heapify(A, smaller, n);
    }
}

int main() {
    scanf("%d %d", &N, &K);

    int* A = new int[N + 1];

    A[0] = 1000000000;
    for (int i = 1; i < N + 1; i++)
        scanf("%d", &A[i]);

    heap_sort(A);

    printf("-1\n");

	return 0;
}