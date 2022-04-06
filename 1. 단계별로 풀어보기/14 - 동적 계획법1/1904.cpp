#include <iostream>
using namespace std;

long long arr[1000001] = {0, 1, 2, };

// ���̰� N�� ��� 2�� ������ ����
long long fibo(int n) {
    // �̹� ����� ���� �ִ� ��
    if (arr[n] != 0)
        return arr[n] % 15746;

    return arr[n] = (fibo(n - 1) + fibo(n - 2)) % 15746;
}

int main() {
    long long N;
    cin >> N;   

    // ���
    if (N == 1)
        printf("1\n");
    else
        cout << fibo(N) << "\n";

    return 0;
}