#include <iostream>
#include <algorithm>
using namespace std;

int semo[501][501] = {};

int main() {
    // 삼각형의 크기
    int n; 
    cin >> n;

    // 합이 최대가 되는 경로에 있는 수의 합
    int big = -1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            // 삼각형을 이루는 수 입력
            scanf("%d", &semo[i][j]);

            // 삼각형의 왼쪽 변
            if (j == 1)
                semo[i][j] += semo[i - 1][j];
            // 삼각형의 오른쪽 변
            else if (j == i)
                semo[i][j] += semo[i - 1][j - 1];
            // 삼각형 중간의 숫자
            else 
                semo[i][j] += max(semo[i - 1][j - 1], semo[i - 1][j]);

            // 최대합 찾기
            if (semo[i][j] > big && i == n)
                big = semo[i][j];
        }
    }

    // 출력
    cout << big << "\n";
        
    return 0;
}