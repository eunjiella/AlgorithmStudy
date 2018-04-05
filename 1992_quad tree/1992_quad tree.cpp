#include <iostream>
#include <string>

using namespace std;
int num[64][64];

void div(int rs, int re, int cs, int ce) {
	int tmp = num[rs][cs], f = 0;

	for (int i = rs; i <= re; i++) {
		for (int j = cs; j <= ce; j++) {
			if (num[i][j] != tmp) {
				f = 1;
				break;
			}
			if (f) break;
		}
	}
	if (f) {
		printf("(");
		div(rs, (rs + re) / 2, cs, (cs + ce) / 2);
		div(rs, (rs + re) / 2, (cs + ce) / 2 + 1, ce);
		div((rs + re) / 2 + 1, re, cs, (cs + ce) / 2);
		div((rs + re) / 2 + 1, re, (cs + ce) / 2 + 1, ce);
		printf(")");
	}
	else printf("%d", tmp);
}
int main() {
	int n, j;
	string s;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> s;
		j = 0;
		for each (char c in s) {
			num[i][j++] = c - '0';
		}
	}
	div(0, n - 1, 0, n - 1);
}