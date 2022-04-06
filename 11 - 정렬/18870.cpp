#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct coordinate {
    int idx1; // 입력할 때 인덱스
    int idx2; // 정렬한 뒤 인덱스
    int x;
};

// 오름차순
bool compare1(coordinate &a, coordinate &b) {
    return a.x < b.x;
}

// 정렬을 원래대로 돌리기
bool compare2(coordinate& a, coordinate& b) {
    return a.idx1 < b.idx1;
}

int main() {
	int N;
	cin >> N;

	vector<coordinate> x(N);

    // 입력
    for (int i = 0; i < N; i++) {
        cin >> x[i].x;
        x[i].idx1 = i;
    }  

    // 정렬
    sort(x.begin(), x.end(), compare1);

    // 작은 수의 개수 찾기
    int count = 0;
    x[0].idx2 = 0;
    for (int i = 1; i < N; i++) {
        if(x[i].x == x[i - 1].x)
            x[i].idx2 = count;
        else {
            count++;
            x[i].idx2 = count;
        }
    }

    // 정렬을 원래대로 돌리기
    sort(x.begin(), x.end(), compare2);

    // 출력
    for (int i = 0; i < N; i++)
        cout << x[i].idx2 << " ";

	return 0;
}