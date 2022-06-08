#include <iostream>
using namespace std;

int main() {
    // 테스트 케이스
    string T;

    while (true) {
        cin >> T;

        // 0 입력 시 반복문 종료
        if (T == "0") break;

        int idx = T.length() / 2;
        int count = 0;

        // 팰린드롬수인지 확인한다.
        for (int i = 0; i < idx; i++) {
            if (T[i] == T[T.length() - i - 1])
                count++;
        }

        // 출력
        if (count == idx)
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}