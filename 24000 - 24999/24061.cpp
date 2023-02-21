#include <iostream>
using namespace std;

void merge(int A[], int p, int q, int r);
void merge_sort(int A[], int p, int r);

int* A, * tmp;
int N, K; // 배열 A의 크기 N, 저장 횟수 K
int cnt = 0; // 저장 횟수
bool isCntK = false;

// A[p..q]와 A[q + 1..r]을 병합하여 A[p..r]을 오름차순 정렬된 상태로 만든다.
// A[p..q]와 A[q + 1..r]은 이미 오름차순으로 정렬되어 있다.
void merge(int A[], int p, int q, int r) {
    int i = p;
    int j = q + 1;
    int t = 1;

    while (i <= q && j <= r) {
        if (A[i] <= A[j])
            tmp[t++] = A[i++];
        else
            tmp[t++] = A[j++];
    }

    // 왼쪽 배열 부분이 남은 경우
    while (i <= q)
        tmp[t++] = A[i++];

    // 오른쪽 배열 부분이 남은 경우
    while (j <= r)
        tmp[t++] = A[j++];

    i = p;
    t = 1;

    // 결과를 A[p..r]에 저장
    while (i <= r) {
        A[i++] = tmp[t++];
        cnt++;

        // K 번째 저장
        if (cnt == K) {
            isCntK = true;

            // 출력
            for (int i = 0; i < N; i++)
                printf("%d ", A[i]);

            break;
        }
    }
}

void merge_sort(int A[], int p, int r) {
    if (isCntK) return;

    //A[p..r]을 오름차순 정렬한다.
    if (p < r) {
        int q = (p + r) / 2;        // q는 p, r의 중간 지점

        merge_sort(A, p, q);        // 전반부 정렬
        merge_sort(A, q + 1, r);    // 후반부 정렬
        merge(A, p, q, r);          // 병합
    }
}


int main() {
    scanf("%d %d", &N, &K);

    A = new int[N + 1];
    tmp = new int[N + 1];

    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    merge_sort(A, 0, N - 1);

    if (!isCntK) printf("-1\n");

    delete[] A;
    delete[] tmp;

    return 0;
}