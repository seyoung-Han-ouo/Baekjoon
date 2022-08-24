#include <iostream>
using namespace std;

int arr[1001][5] = {};
int student[1001] = {}; // 같은 반이었던 학생 수
bool check[1001][1001] = { false }; // 중복 제외를 위한 배열

int main() {
    int N; // 반의 학생 수
    cin >> N;

    // 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++)
            scanf("%d", &arr[i][j]);
    }

    int lot = 0; // 같은 반이었던 학생 수 중 가장 큰 수
    int idx = 0; // 임시 반장의 번호

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                // 같은 반이었던 적이 있는 지 확인한다.
                if (j != k && arr[j][i] == arr[k][i] && check[j][k] == false) {
                    student[j]++;
                    student[k]++;  

                    check[j][k] = true;
                    check[k][j] = true;
                }

                // 같은 반이었던 학생 수가 가장 많은 학생 찾기
                if (student[j] > lot) {
                    lot = student[j];
                    idx = j;
                }
            }
        }
    }

    // 출력
    cout << idx + 1;

    return 0;
}