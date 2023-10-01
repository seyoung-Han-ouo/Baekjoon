#include <iostream>
#include <vector>
using namespace std;

int N, M, cnt;
vector<int> party[50], truth;
bool person[51], check[51];

void checkPerson();
void checkParty(int n);

// ó������ ������ �˰� �ִ� ��� üũ�ϱ�
void checkPerson() {
    for (int n : truth) {
        if (!person[n]) {
            person[n] = true;
            checkParty(n);
        }
    }
}

// ������ �̾߱��ϴ� ��Ƽ üũ�ϱ�
void checkParty(int n) {
    for (int i = 0; i < M; i++) {
        if (!check[i]) {
            for (int j : party[i]) {
                if (j == n) {
                    check[i] = true;
                    cnt--;

                    // ���� ������ ���� ��� üũ�ϱ�
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