#include <iostream>
using namespace std;

int main() {
    int sum[81] = { 0 };

    int S1, S2, S3; // 주사위의 면
    cin >> S1 >> S2 >> S3;

    int lot = 0; // 가장 많이 발생한 합의 횟수
    int indx = 80; // 가장 많이 발생하는 합

    for (int i = 1; i <= S1; i++) {
        for (int j = 1; j <= S2; j++) {
            for (int k = 1; k <= S3; k++) {
                int n = i + j + k;
                sum[n]++;

                // 가장 많이 발생하는 합 찾기
                if (sum[n] > lot) {
                    lot = sum[n];
                    indx = n;
                } 

                // 가장 많이 발생하는 합이 여러개라면 가장 합이 작은 것을 선택
                if (sum[n] == sum[indx] && n < indx)
                    indx = n;
            }
        }
    }

    // 출력
    cout << indx;

    return 0;
}