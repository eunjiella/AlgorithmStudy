#include <stdio.h>

int main() {
	int num, change, count = 0, coin[10];

	scanf("%d %d", &num, &change);
	for (int i = 0; i < num; i++)
		scanf("%d", &coin[i]);

	while (change != 0) {
		if (change < coin[0])
			printf("fail\n");
		if (change >= coin[num - 1]) {
			count += change / coin[num - 1];
			change %= coin[num - 1];
		}
		else num--;
	}
	printf("%d", count);
}
