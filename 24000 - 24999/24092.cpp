#include <iostream>
#include <vector>
using namespace std;

bool isSame();
void print(int n);
void quick_sort(int p, int r);
int partition(int p, int r);

int N; // 배열의 크기 N
int sameIdx = -1; // 두 배열이 같은 인덱스
vector <int> A(10001);
vector <int> B(10001);

// 두 배열이 같은가?
bool isSame() {
    if (sameIdx < 0) sameIdx = 0;

    for (int i = sameIdx; i < N; i++) {
        if (A[i] != B[i]) {
            sameIdx = i - 1;
            return false;
        }
    }

    return true;
}

// 출력
void print(int n) {
    printf("%d\n" , n);
    exit(0);
}

// A[p..r]을 오름차순 정렬한다.
void quick_sort(int p, int r) {
    if (p < r) {
        int q = partition(p, r); // 분할

        quick_sort(p, q - 1);    // 왼쪽 부분 배열 정렬
        quick_sort(q + 1, r);    // 오른쪽 부분 배열 정렬
    }
}

int partition(int p, int r) {
    int x = A[r]; // 기준원소
    int i = p - 1; // i는 x보다 작거나 작은 원소들의 끝지점

    // j는 아직 정해지지 않은 원소들의 시작 지점
    for (int j = p; j < r; j++) {
        // i값 증가 후 A[i], A[j] 교환
        if (A[j] <= x) {
            int tmp = A[++i];
            A[i] = A[j];
            A[j] = tmp;

            // 배열 A가 배열 B와 같은 경우
            if (A[j] == B[j] || A[i] == B[i])
                if (isSame()) print(1);
        }
    }

    // i + 1과 r이 서로 다르면 A[i + 1]과 A[r]을 교환
    if (i + 1 != r) {
        int tmp = A[r];
        A[r] = A[i + 1];
        A[i + 1] = tmp;

        // 배열 A가 배열 B와 같은 경우
        if (A[i + 1] == B[i + 1] || A[r] == B[r])
            if (isSame()) print(1);
    }

    return i + 1;
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    for (int i = 0; i < N; i++)
        scanf("%d", &B[i]);

    // 배열 A가 배열 B와 같은 경우
    if (A == B) print(1);

    quick_sort(0, N - 1);

    printf("0\n");

	return 0;
}