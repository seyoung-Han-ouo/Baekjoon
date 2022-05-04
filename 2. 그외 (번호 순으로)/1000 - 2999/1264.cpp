#include <iostream>
#include <string>
using namespace std;

char vowel[5] = { 'a', 'e', 'i', 'o', 'u' };

int main() {
    // 테스트 케이스
    string T;

    while (true) {
        getline(cin, T); // 공백 포함 문자열

        // # 입력 시 반복문 종료
        if (T == "#") break;

        int count = 0;  // 모음의 개수

        for (int i = 0; i < T.length(); i++) {
            // 대문자를 소문자로 변환
            if (T[i] >= 'A' && T[i] <= 'Z')
                T[i] += 32;

            // 모음의 개수
            for (int j = 0; j < 5; j++) {
                if (T[i] == vowel[j])
                    count++;
            }
        }

        // 출력
        printf("%d\n", count);
    }

    return 0;
}