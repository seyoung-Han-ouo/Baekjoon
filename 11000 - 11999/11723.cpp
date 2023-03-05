#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M; // 연산의 수
	cin >> M;

	int x, bit = 0;

	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;

		switch (s[1])
		{
		case 'd': // S에 x를 추가한다.
			cin >> x;

			bit |= (1 << x);
			break;

		case 'e': // S에서 x를 제거한다.
			cin >> x;

			bit &= ~(1 << x);
			break;

		case 'h': // S에 x가 있으면 1을, 없으면 0을 출력한다.
			cin >> x;

			if (bit & (1 << x))
				printf("1\n");
			else
				printf("0\n");
			break;

		case 'o': // S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다.
			cin >> x;

			bit ^= (1 << x);
			break;

		case 'l': // S를{ 1, 2, ..., 20 } 으로 바꾼다.
			bit = (1 << 21) - 1;
			break;

		case 'm': // S를 공집합으로 바꾼다.
			bit = 0;
			break;
		}
	}

	return 0;
}