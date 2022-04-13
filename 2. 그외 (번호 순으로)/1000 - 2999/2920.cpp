#include <iostream>
using namespace std;

int main() {
    // 연주한 순서가 ascending인지, descending인지 판별
    bool isAc = false;
    bool isDs = false;

    // 입력
    int num1;
    cin >> num1;

    for (int i = 0; i < 7; i++) {
        // 고유번호의 처음 5자리
        int num2;
        cin >> num2;

        if (num1 < num2)
            isAc = true;
        else if (num1 > num2)
            isDs = true;

        num1 = num2;
    }

    // 출력
    if (isAc && isDs) // isAc, isDs가 둘다 참이면 mixed이다.
        cout << "mixed\n";
    else if (isAc)
        cout << "ascending\n";
    else
        cout << "descending\n";

    return 0;
}