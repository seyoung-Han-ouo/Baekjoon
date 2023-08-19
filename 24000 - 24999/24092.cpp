#include <iostream>
using namespace std;

void quick_sort(int p, int r);
void swap(int i, int j);
void isSame();
int partition(int p, int r);

int N, cnt = 0;
int A[10001], B[10001];

// A[p..r]을 오름차순 정렬한다.
void quick_sort(int p, int r) {
    if (p < r) {
        int q = partition(p, r); // 분할

        quick_sort(p, q - 1);    // 왼쪽 부분 배열 정렬
        quick_sort(q + 1, r);    // 오른쪽 부분 배열 정렬
    }
}

// 원소 교환
void swap(int i, int j) {
    cnt -= ((A[i] == B[i]) + (A[j] == B[j]));

    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;

    cnt += ((A[i] == B[i]) + (A[j] == B[j]));

    isSame();
}

// A와 B 비교
void isSame() {
    if (cnt == N) {
        cout << "1\n";
        exit(0);
    }
}

int partition(int p, int r) {
    int x = A[r];   // 기준원소
    int i = p - 1;  // i는 x보다 작거나 작은 원소들의 끝지점

    // j는 아직 정해지지 않은 원소들의 시작 지점, i값 증가 후 A[i], A[j] 교환
    for (int j = p; j < r; j++)
        if (A[j] <= x) swap(++i, j);

    // i + 1과 r이 서로 다르면 A[i + 1]과 A[r]을 교환
    if (i + 1 != r) swap(r, i + 1);

    return i + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) {
        cin >> B[i];

        if (A[i] == B[i]) cnt++;
    }

    isSame();

    quick_sort(0, N - 1);

    cout << "0\n";

    return 0;
}