#include <iostream>
using namespace std;

// 이미 찾은 수를 또 계산할 필요가 없게 저장한다.
int arr[51][51][51] = {0};

// 재귀함수
int w (int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        arr[a][b][c] = 1;
        return arr[a][b][c];
    }

    if (a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);

    // 이미 계산한 적이 있는 수는 재귀를 하지 않고 배열에서 숫자를 뽑아 사용한다.
    if (arr[a][b][c] != 0)
        return arr[a][b][c];

    if (a < b && b < c)
        return arr[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);

    return arr[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main() {
    int a, b, c;

    while(true) {
        // 입력
        cin >> a >> b >> c;

        // a, b, c가 모두 -1이면 반복 종료
        if (a == -1 && b == -1 && c == -1) break;

        // 출력
        if (a < 0 || b < 0 || c < 0) // a, b, c 중 하나라도 0보다 작을 때
            printf("w(%d, %d, %d) = %d\n", a, b, c, w(0, 0, 0)); 
        else
            printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
    }

    return 0;
}