#include <iostream>
using namespace std;

int main() {
	int m, d;
	scanf("%d %d", &m, &d);

	if (m == 2 && d == 18) 
		printf("Special\n");
	else if ((m == 2 && d > 18) || (m > 2)) 
		printf("After");
	else 
		printf("Before");

	return 0;
}