#include <iostream>
#include <vector>
using namespace std;

bool sameIdx();
void print(int n);
void merge(int p, int q, int r);
void merge_sort(int p, int r);

int N; // 배열 A의 크기 N
int idx = -1;

vector <int> A(500001);
vector <int> B(500001);
vector <int> tmp(500001);

// 배열 A와 배열 B 비교
bool sameIdx() {
    for (int i = idx; i < N; i++) {
        if (i == -1) i = 0;

        if (A[i] != B[i]) {
            idx = i - 1;
            return false;
        }
    }

    return true;
}

// 1, 아니면 0을 출력
void print(int n) {
    printf("%d\n", n);
    exit(0);
}

// A[p..q]와 A[q + 1..r]을 병합하여 A[p..r]을 오름차순 정렬된 상태로 만든다.
// A[p..q]와 A[q + 1..r]은 이미 오름차순으로 정렬되어 있다.
void merge(int p, int q, int r) {
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
        if (A[i] != tmp[t]) {
            // 배열 A가 배열 B와 같은 경우가 없음
            if (i <= idx) print(0);

            A[i++] = tmp[t++];

            // 배열 A가 배열 B와 같은 경우
            if (sameIdx()) print(1);
        }
        else
            A[i++] = tmp[t++];
    }
}

void merge_sort(int p, int r) {
    if (sameIdx()) print(1);

    //A[p..r]을 오름차순 정렬한다.
    if (p < r) {
        int q = (p + r) / 2;    // q는 p, r의 중간 지점

        merge_sort(p, q);       // 전반부 정렬
        merge_sort(q + 1, r);   // 후반부 정렬
        merge(p, q, r);         // 병합
    }
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    for (int i = 0; i < N; i++)
        scanf("%d", &B[i]);

    merge_sort(0, N - 1);

    printf("0\n");

    return 0;
}