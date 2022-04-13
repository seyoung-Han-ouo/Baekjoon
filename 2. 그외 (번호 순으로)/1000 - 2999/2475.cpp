#include <iostream>
using namespace std;

int main() {
    // 각 숫자를 제곱한 수들의 합
    int sum = 0;

    for (int i = 0; i < 5; i++) {
        // 고유번호의 처음 5자리
        int num;
        cin >> num;

        sum += (num * num);
    }

    //  각 숫자를 제곱한 수들의 합을 10으로 나눈 나머지 출력
    cout << sum % 10;

    return 0;
}