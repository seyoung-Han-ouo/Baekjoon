#include <iostream>
using namespace std;

int main() {
    string N;
    cin >> N;

    bool isYou = false; // 유진수 여부
    int m1 = 1; // 앞부분 자리수의 곱

    for (int i = 0; i < N.length() - 1; i++) {
        m1 *= N[i] - '0';

        // 뒷부분 자리수의 곱
        int m2 = 1;
        for (int j = i + 1; j < N.length(); j++)
            m2 *= N[j] - '0';

        // 유진수인지 확인한다.
        if (m1 == m2) {
            isYou = true;
            break;
        }
    }

    // 출력
    if (isYou == true)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}