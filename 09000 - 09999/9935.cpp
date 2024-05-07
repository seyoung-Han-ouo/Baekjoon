#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

stack<char> sk;
stack<char> result;

void move(stack<char>& a, stack<char>& b);

// a�� ���Ҹ� b�� ��� �ű�� �Լ�
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

    reverse(bomb.begin(), bomb.end()); // ���� ���ڿ� ������

    for (char c : s) {
        sk.push(c);

        if (c != bomb[0] || sk.size() < bomb.length()) continue;

        stack<char> save;

        // ���� ���ڿ��� ���ԵǾ� �ִ��� Ȯ���ϱ�
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

    // ���
    if (result.empty()) cout << "FRULA\n";

    while (!result.empty()) {
        cout << result.top();
        result.pop();
    }

    return 0;
}