#include<iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int layer = 1; //1은 1층, 2 ~ 7은 2층... 각 층의 방 수는 6의 배수로 늘어난다.
	int layerNum = 1;

	if (N != 1){
		while (true) {
			// N이 layerNum보다 작으므로 해당 layer에 위치한 숫자이다.
			if (N <= layerNum) break;

			// N이 layerNum보다 작지 않을 때
			layerNum += 6 * layer++;
		}
	}
	cout << layer; // 시작과 끝을 모두 포함하기 때문에 1을 더한다.

	return 0;
}