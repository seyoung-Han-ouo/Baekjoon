#include <iostream>
using namespace std;

long long arr[1000001] = {0, 1, 2, };

// 길이가 N인 모든 2진 수열의 개수
long long fibo(int n) {
    // 이미 계산한 적이 있는 수
    if (arr[n] != 0)
        return arr[n] % 15746;

    return arr[n] = (fibo(n - 1) + fibo(n - 2)) % 15746;
}

int main() {
    long long N;
    cin >> N;   

    // 출력
    if (N == 1)
        printf("1\n");
    else
        cout << fibo(N) << "\n";

    return 0;
}