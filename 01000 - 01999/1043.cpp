#include <iostream>
#include <vector>
using namespace std;

int N, M, cnt;
vector<int> party[50], truth;
bool person[51], check[51];

void checkPerson();
void checkParty(int n);

// 처음부터 진실을 알고 있던 사람 체크하기
void checkPerson() {
    for (int n : truth) {
        if (!person[n]) {
            person[n] = true;
            checkParty(n);
        }
    }
}

// 진실을 이야기하는 파티 체크하기
void checkParty(int n) {
    for (int i = 0; i < M; i++) {
        if (!check[i]) {
            for (int j : party[i]) {
                if (j == n) {
                    check[i] = true;
                    cnt--;

                    // 새로 진실을 들은 사람 체크하기
                    for (int k : party[i]) {
                        if (!person[k]) {
                            person[k] = true;
                            checkParty(k);
                        }
                    }

                    break;
                }
            }
        }
    }
}

int main()
{
    int num;
    cin >> N >> M >> num;

    while (num--) {
        int n;
        cin >> n;

        truth.push_back(n);
    }

    for (int i = 0; i < M; i++) {
        cin >> num;
        while (num--) {
            int n;
            cin >> n;

            party[i].push_back(n);
        }
    }

    cnt = M;
    checkPerson();

    cout << cnt << '\n';

    return 0;
}