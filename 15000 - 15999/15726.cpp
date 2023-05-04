#include <iostream>
using namespace std;

int main() {
	long long a, b, c;
	cin >> a >> b >> c;

	long long n1 = (double)(a * b) / c;
	long long n2 = ((double) a / b) * c;

	if (n1 > n2) 
		cout << n1;
	else 
		cout << n2;

	return 0;
}