#include <iostream>
using namespace std;

long long arr[101] = { 0, 1, 1, 1, };

// N번째 정삼각형 찾기
long long semo(int n) {
    // 이미 찾은 적이 있다면
    if (arr[n] != 0)
        return arr[n];

    return arr[n] = semo(n - 2) + semo(n - 3);
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N;
        scanf("%d", &N);

        // 출력
        cout << semo(N) << "\n";
    }

    return 0;
}