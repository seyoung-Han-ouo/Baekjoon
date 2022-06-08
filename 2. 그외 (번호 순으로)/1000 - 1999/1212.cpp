#include <iostream>
#include <bitset>
#include <string>

using namespace std;

int main() {
    // 입력
    string s;
    cin >> s;

    // 입력한 값이 0일 때
    if (s == "0")
        cout << 0;
    else {
        for (int i = 0; i < s.length(); i++) {
            // 2진수로 변환
            string num = (bitset<3>((int)s[i])).to_string();

            // 출력
            if (i == 0) {
                int n = stoi(num);
                cout << n;
            }
            else
                cout << num;
        }
    }

    return 0;
}