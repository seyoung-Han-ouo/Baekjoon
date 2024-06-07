#include <iostream>
#include <algorithm>
using namespace std;

int N;              // 과일의 개수
int num[10];        // 각 종류별 사용한 수
int fruit[200000];  // 탕후루의 과일들

bool checkCnt();
int makeTanghulu();

// 사용한 과일의 수가 두 종류 이하인가?
bool checkCnt() {
    int cnt = 0;

    for (int i = 1; i < 10; i++) {
        if (num[i] > 0) cnt++;

        if (cnt > 2) return false;
    }

    return true;
}

// 과일을 두 종류 이하로 사용한 탕후루 만들기
int makeTanghulu() {
    int left = 0;
    int right = 0;
    int result = 0;

    while (left < N) {
        while (right < N) {
            num[fruit[right++]]++;

            if (!checkCnt()) {
                right--;
                num[fruit[right]]--;

                break;
            }
        }

        result = max(result, right - left);

        num[fruit[left++]]--;
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> fruit[i];

    cout << makeTanghulu() << '\n';

    return 0;
}