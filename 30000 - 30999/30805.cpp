#include <iostream>
#include <vector>
using namespace std;

int N, M;
int A[101];
int B[101];
vector<int> same;

void findSame(int startA, int startB);

void findSame(int startA, int startB) {
    if (startA >= N || startB >= M) return;

    vector<int> a(101, -1);
    vector<int> b(101, -1);

    // 매개변수보다 뒤에 위치한 원소로 a와 b 초기화
    for (int i = startA; i < N; i++) if (a[A[i]] == -1) a[A[i]] = i;
    for (int i = startB; i < M; i++) if (b[B[i]] == -1) b[B[i]] = i;

    for (int i = 100; i > 0; i--) {
        if (a[i] == -1 || b[i] == -1) continue;

        same.push_back(i);
        findSame(a[i] + 1, b[i] + 1);

        break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    cin >> M;
    for (int i = 0; i < M; i++) cin >> B[i];

    findSame(0, 0);

    // 출력
    cout << same.size() << '\n';
    for (int i = 0; i < same.size(); i++)
        cout << same[i] << ' ';
    cout << '\n';

    return 0;
}