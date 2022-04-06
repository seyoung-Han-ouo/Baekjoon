#include <iostream>
using namespace std;

// 피보나치 수 저장
int fibo[41] = {0, 1, };

// N번째 피보나치 수를 구하는 함수
int fibonacci(int n) {
    if (n == 0 || n == 1)
        return fibo[n];
    else if (fibo[n] == 0)
        return fibo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    else
        return fibo[n];
}

int main() {
    int T; // 테스트 케이스의 개수
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        // 입력
        int N;
        scanf("%d", &N);

        fibonacci(N);

        // 출력
        if (N == 0) 
            printf("1 0\n");
        else
            printf("%d %d\n", fibo[N - 1], fibo[N]);
    }

    return 0;
}