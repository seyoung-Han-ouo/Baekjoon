#include <iostream>
#include <cmath>
using namespace std;

int main() {
    string f[51]; // 파일 이름 저장
    bool difr[51] = { false }; // ?을 넣을 위치 저장

    int N; // 파일 이름의 개수 N
    cin >> N; 

    for (int i = 0; i < N; i++) {
        // 입력
        cin >> f[i];

        // 입력된 파일이름을 비교해서 ?로 바꿀 부분 찾기
        if (i > 0) {
            for (int j = 0; j < f[i - 1].length(); j++) {
                if (f[i][j] != f[i - 1][j])
                    difr[j] = true;
            }
        }
    }

    // 출력
    for (int i = 0; i < f[0].length(); i++) {
        if (difr[i] == true)
            printf("?");
        else
            cout << f[0][i];
    }

    return 0;
}