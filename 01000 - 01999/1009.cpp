#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T; // �׽�Ʈ ���̽� T
    cin >> T; 

    for (int i = 0; i < T; i++) {
        int a, b;

        scanf("%d %d", &a, &b);

        int num1 = b % 4;
        if (num1 == 0)
            num1 = 4;

        // ������ �����Ͱ� ó���� įǻ�� ã��
        int result = (int)pow(a % 10, num1) % 10;
        if (result == 0)
            result = 10;

        printf("%d\n", result);
    }

    return 0;
}