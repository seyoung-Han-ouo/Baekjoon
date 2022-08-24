#include <iostream>
using namespace std;

int main() {
    // 하얀 칸 위 말의 수
    int white = 0; 

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char c;
            cin >> c;

            // 입력한 문자의 위치가 하얀 칸인지 확인한다.
            if (c == 'F') {
                if (i % 2 == 0 && j % 2 == 0)
                    white++;
                if (i % 2 == 1 && j % 2 == 1)
                    white++;
            }
        }
    }

    // 출력
    cout << white;

    return 0;
}