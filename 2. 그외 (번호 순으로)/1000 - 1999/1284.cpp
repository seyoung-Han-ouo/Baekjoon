#include <iostream>
using namespace std;

int main() {
    while (true) {
        string N; // 호수판에 들어갈 숫자 N
        cin >> N;

        // 0 입력 시 반복 종료
        if (N == "0") break;

        // 호수판 너비
        int num = N.length() + 1;

        for (int i = 0; i < N.length(); i++) {
            if (N[i] == '0')
                num += 4;
            else if (N[i] == '1')
                num += 2;
            else 
                num += 3;
        }

        // 출력
        printf("%d\n", num);
    }

    return 0;
}