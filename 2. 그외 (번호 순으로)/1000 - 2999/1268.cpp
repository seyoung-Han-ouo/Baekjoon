#include <iostream>
using namespace std;

int arr[1001][5] = {};
int student[1001] = {}; // ���� ���̾��� �л� ��
bool check[1001][1001] = { false }; // �ߺ� ���ܸ� ���� �迭

int main() {
    int N; // ���� �л� ��
    cin >> N;

    // �Է�
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++)
            scanf("%d", &arr[i][j]);
    }

    int lot = 0; // ���� ���̾��� �л� �� �� ���� ū ��
    int idx = 0; // �ӽ� ������ ��ȣ

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                // ���� ���̾��� ���� �ִ� �� Ȯ���Ѵ�.
                if (j != k && arr[j][i] == arr[k][i] && check[j][k] == false) {
                    student[j]++;
                    student[k]++;  

                    check[j][k] = true;
                    check[k][j] = true;
                }

                // ���� ���̾��� �л� ���� ���� ���� �л� ã��
                if (student[j] > lot) {
                    lot = student[j];
                    idx = j;
                }
            }
        }
    }

    // ���
    cout << idx + 1;

    return 0;
}