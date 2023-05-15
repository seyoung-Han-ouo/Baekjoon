#include <iostream>
using namespace std;

int main() {
	int N, W, H, L;
	scanf("%d %d %d %d", &N, &W, &H, &L);

	int num = (W / L) * (H / L);
	num = num > N ? N : num;

	printf("%d\n", num);

	return 0;
}