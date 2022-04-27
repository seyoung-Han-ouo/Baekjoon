#include <iostream>
using namespace std;

int main() {
    int alpha[26] = {};  // 성의 첫 글자가 같은 사람 수
    bool giveUp = false; // 선수 선발 가능 여부

    int N; // 선수의 수
    cin >> N;

    // 입력
    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;

        alpha[name[0] - 'a']++;

        // 성의 첫 글자가 같은 선수가 5명보다 많을 때
        if (alpha[name[0] - 'a'] >= 5) 
            giveUp = true;
    }

    // 출력
    if (giveUp == false)  // 선수 다섯 명을 선발할 수 없는 경우
        cout << "PREDAJA";
    else {
        for (int i = 0; i < 26; i++) {
            if (alpha[i] >= 5)
                cout << (char)(i + 'a');
        }
    }

    return 0;
}