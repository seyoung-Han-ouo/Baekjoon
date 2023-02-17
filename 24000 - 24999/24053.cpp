#include <iostream>
#include <vector>
using namespace std;

int insertion_sort(int N);

vector <int> A(10001);
vector <int> B(10001);

// 삽입 정렬
int insertion_sort(int N) {
    //A[]을 오름차순 정렬한다.
    for (int i = 1; i < N; i++) {
        int loc;
        int newItem = A[i];

        // 이 지점에서 A[1..i - 1]은 이미 정렬되어 있는 상태
        for (loc = i - 1; loc >= 0 && newItem < A[loc]; loc--) {
            A[loc + 1] = A[loc];

            //  배열 A가 배열 B와 같은 경우
            if (A == B) return 1;
        }

        if (loc + 1 != i) {
            A[loc + 1] = newItem;

            //  배열 A가 배열 B와 같은 경우
            if (A == B) return 1;
        }
    }

    return 0;
}

int main() {
	int N; //  배열의 크기 N
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

    for (int i = 0; i < N; i++)
        scanf("%d", &B[i]);

    // 출력
    printf("%d\n", insertion_sort(N));

	return 0;
}