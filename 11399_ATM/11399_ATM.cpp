#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int num, tmp, sum;
	vector<int> input;

	scanf("%d", &num);
	do {
		scanf("%d", &tmp);
		input.push_back(tmp);
	} while (getc(stdin) == ' '); //숫자 여러개 한줄로 입력받기

	sort(input.begin(), input.end());

	sum = input[0];
	for (int i = 1; i < num; i++) {
		input[i] += input[i - 1];
		sum += input[i];
	}
	cout << sum;
}