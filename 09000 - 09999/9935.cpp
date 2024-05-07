#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

stack<char> sk;
stack<char> result;

void move(stack<char>& a, stack<char>& b);

// a의 원소를 b로 모두 옮기는 함수
void move(stack<char>& a, stack<char>& b) {
    while (!a.empty()) {
        b.push(a.top());
        a.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s, bomb;
    cin >> s >> bomb;

    reverse(bomb.begin(), bomb.end()); // 폭발 문자열 뒤집기

    for (char c : s) {
        sk.push(c);

        if (c != bomb[0] || sk.size() < bomb.length()) continue;

        stack<char> save;

        // 폭발 문자열이 포함되어 있는지 확인하기
        for (char b : bomb) {
            if (sk.top() == b) {
                save.push(sk.top());
                sk.pop();
            }
            else {
                move(save, sk);
                break;
            }
        }
    }

    move(sk, result);

    // 출력
    if (result.empty()) cout << "FRULA\n";

    while (!result.empty()) {
        cout << result.top();
        result.pop();
    }

    return 0;
}