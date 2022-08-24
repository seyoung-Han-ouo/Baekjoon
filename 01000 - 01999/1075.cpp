#include <iostream>
using namespace std;

int main() {
    int N, F;
    cin >> N >> F;

    int num;
    for (int i = 0; i < 100; i++) {
        // N의 뒤 두 자리수를 변경하면서 F로 나누어 떨어지는 수 찾기
        num = (N / 100) * 100 + i;

        if (num % F == 0) {
            num = i;
            break;
        }
    }

    // 출력
    if (num < 10)
        printf("0%d\n", num);
    else
        printf("%d", num);

    return 0;
}