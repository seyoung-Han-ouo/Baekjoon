#include <iostream>
using namespace std;

int main() {
    int N; // 동호가 저번 달에 이용한 통화의 개수
    cin >> N;

    // 금액 청구 인정되는 시간
    int yCount = 0, mCount = 0;
    for (int i = 0; i < N; i++) {
        int M;
        cin >> M;

        yCount += (M / 30) + 1;
        mCount += (M / 60) + 1;
    }

    // 각 요금제별 청구 금액
    int yCost = yCount * 10;
    int mCost = mCount * 15;

    // 출력
    if (yCost < mCost)
        printf("Y %d\n", yCost);
    else if (yCost == mCost)
        printf("Y M %d\n", yCost);
    else
        printf("M %d", mCost);

    return 0;
}