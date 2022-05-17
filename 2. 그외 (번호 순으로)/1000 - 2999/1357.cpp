#include <iostream>
#include <cmath>
using namespace std;

// 모든 자리수를 역순으로 만드는 함수
int Rev(int num) {
    int rNum = 0;

    int idx = 0; // num의 길이
    int num1 = num;

    // num 길이 구하기
    for (int i = 0; ; i++) {
        num1 /= 10;
        idx++;

        if (num1 == 0)
            break;
    }

    // 숫자를 역순으로 바꾸기
    for (int i = idx - 1; i >= 0; i--) {
        rNum += num % 10 * pow(10, i);
        num /= 10;
    }

    return rNum;
}

int main() {
    int X, Y;
    cin >> X >> Y;

    // 출력
    cout << Rev(Rev(X) + Rev(Y)) << endl;

    return 0;
}