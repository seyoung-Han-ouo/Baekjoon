#include <iostream>
#include <cmath>
using namespace std;

// 저항의 색
string color[10] = { "black", "brown", "red", "orange", "yellow",
                    "green", "blue", "violet", "grey", "white" };

int main() {
    int sum = 0; // 저항의 값

    for (int i = 0; i < 3; i++) {
        // 입력
        string c;
        cin >> c;

        // 입력한 색이 color[]의 몇 번 인덱스에 해당하는 지 찾기
        int j = 0;
        for (j; j < 10; j++)
            if (c == color[j]) break;

        // 저항의 값 계산
        if (i <= 1)
            sum += (j * pow(10, 1 - i));
        else { // 출력
            cout << sum;

            if (sum > 0) {
                for (int k = 0; k < j; k++)
                    cout << "0";
            }
        }
    }

    return 0;
}