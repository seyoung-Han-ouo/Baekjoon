#include <iostream>
using namespace std;

int main() {
    int N, F;
    cin >> N >> F;

    int num;
    for (int i = 0; i < 100; i++) {
        // N�� �� �� �ڸ����� �����ϸ鼭 F�� ������ �������� �� ã��
        num = (N / 100) * 100 + i;

        if (num % F == 0) {
            num = i;
            break;
        }
    }

    // ���
    if (num < 10)
        printf("0%d\n", num);
    else
        printf("%d", num);

    return 0;
}