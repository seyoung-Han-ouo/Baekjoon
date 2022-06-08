#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int num[160] = {};
    bool isZero = false;

    // 두 이진수 중 더 긴 것을 a에 저장한다.
    if (a.length() < b.length()) {
        string c = a;
        a = b;
        b = c;
    }

    // 계산하기 편하게 하기 위해 배열을 뒤집는다.
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int idx = a.length();

    // 이진수 덧셈
    for (int i = 0; i < a.length(); i++) {
        if (i < b.length())
            num[i] += (a[i] - '0') + (b[i] - '0');
        else
            num[i] += (a[i] - '0');

        
        if (num[i] != 0)
            isZero = true;

        // 받아올림
        if (num[i] >= 2) {
            num[i] -= 2;
            num[i + 1]++;

            if (i == a.length() - 1) idx++;
        }
    }

    // 출력
    // 답이 0인지 확인한다.
    if (isZero == false)
        cout << "0\n";
    else {
        // 필요 없는 0 제거하기 위한 변수
        bool start = false;

        // 출력
        for (int i = idx - 1; i >= 0; i--) {
            if (num[i] == 1)
                start = true;

            if (start == true)
                printf("%d", num[i]);
        }
    }

    return 0;
}