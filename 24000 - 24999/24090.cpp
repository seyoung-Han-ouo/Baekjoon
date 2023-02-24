#include <iostream>
using namespace std;

void quick_sort(int A[], int p, int r);
int partition(int A[], int p, int r);

int N, K; // 배열의 크기 N, 교환 횟수 K
int cnt = 0; // 교환 횟수

// A[p..r]을 오름차순 정렬한다.
void quick_sort(int A[], int p, int r) {
    if (p < r) {
        int q = partition(A, p, r); // 분할

        quick_sort(A, p, q - 1);    // 왼쪽 부분 배열 정렬
        quick_sort(A, q + 1, r);    // 오른쪽 부분 배열 정렬
    }
}

int partition(int A[], int p, int r) {
    int x = A[r]; // 기준원소
    int i = p - 1; // i는 x보다 작거나 작은 원소들의 끝지점

    // j는 아직 정해지지 않은 원소들의 시작 지점
    for (int j = p; j < r; j++) {
        // i값 증가 후 A[i], A[j] 교환
        if (A[j] <= x) {
            int tmp = A[++i];
            A[i] = A[j];
            A[j] = tmp;

            // K 번째 교환
            if (++cnt == K) {
                printf("%d %d\n", min(A[i], A[j]), max(A[i], A[j]));
                exit(0);
            }
        }
    }

    // i + 1과 r이 서로 다르면 A[i + 1]과 A[r]을 교환
    if (i + 1 != r) {
        int tmp = A[r];
        A[r] = A[i + 1];
        A[i + 1] = tmp;
        
        // K 번째 교환
        if (++cnt == K) {
            printf("%d %d\n", min(A[r], A[i + 1]), max(A[r], A[i + 1]));
            exit(0);
        }
    }

    return i + 1;
}

int main() {
    scanf("%d %d", &N, &K);

    int* A = new int[N];

    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    quick_sort(A, 0, N - 1);

    printf("-1\n");

	return 0;
}