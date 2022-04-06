#include <iostream>
using namespace std;

// �Ǻ���ġ �� ����
int fibo[41] = {0, 1, };

// N��° �Ǻ���ġ ���� ���ϴ� �Լ�
int fibonacci(int n) {
    if (n == 0 || n == 1)
        return fibo[n];
    else if (fibo[n] == 0)
        return fibo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    else
        return fibo[n];
}

int main() {
    int T; // �׽�Ʈ ���̽��� ����
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        // �Է�
        int N;
        scanf("%d", &N);

        fibonacci(N);

        // ���
        if (N == 0) 
            printf("1 0\n");
        else
            printf("%d %d\n", fibo[N - 1], fibo[N]);
    }

    return 0;
}