#include <iostream>
using namespace std;

int main() {
    int num[5]; // 다섯 개의 자연수 
    int smallNum = 101; // 입력한 수 중 가장 작은 수 
    int small = 100000000; // 가장 작은 대부분의 배수 저장

    // 입력
    for (int i = 0; i < 5; i++) {
        cin >> num[i];

        // 입력한 숫자 중에서 가장 작은 수 찾기
        if (num[i] < smallNum)
            smallNum = num[i];
    }

    // 가장 작은 대부분의 배수 찾기
    for (int i = smallNum; ; i++) {
        // n이 num[]의 숫자로 나누어 떨어지는 횟수 구하기
        int count = 0;
        for (int j = 0; j < 5; j++)
            if (i % num[j] == 0) count++;

        // 대부분의 배수 찾았을 때
        if (count >= 3) {
            small = i;
            break;
        }
    }

    // 출력
    cout << small;

    return 0;
}