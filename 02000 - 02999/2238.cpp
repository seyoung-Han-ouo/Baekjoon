#include <iostream>
using namespace std;

#define MAX 10001

int price[MAX];     // 각 가격으로 입찰한 사람의 수
string name[MAX];   // 가장 먼저 해당 가격으로 제시한 사람

int findResult();

int findResult() {
    int cnt = 100001;
    int result = 0;

    for (int i = 1; i < MAX; i++) {
        // 해당 가격을 제시한 사람이 없을때
        if (price[i] == 0) continue;

        // 더 적은 수의 사람이 입찰한 가격일때
        if (price[i] < cnt) {
            cnt = price[i];
            result = i;
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int U, N;
    cin >> U >> N;

    while (N--) {
        string s;
        int p;
        cin >> s >> p;

        // 해당 가격으로 가장 먼저 제시한 사람의 이름 저장
        if (price[p] == 0) name[p] = s;

        price[p]++;
    }

    // 출력
    int result = findResult();
    cout << name[result] << ' ' << result << '\n';

    return 0;
}