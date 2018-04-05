#include <iostream>
#include <cmath>

using namespace std;
int main() {
	int f, m, num, intern;
	scanf("%d %d %d", &f, &m, &intern);

	num = (f / 2 < m) ? f / 2 : m;
	f -= 2 * num;
	m -= num;

	intern -= (m + f);
	if (intern>0) //teamÀ» ±ú¾ßÇÒ ¶§	
		num -= ceil((double)intern / 3);

	printf("%d", (num > 0) ? num : 0);
}