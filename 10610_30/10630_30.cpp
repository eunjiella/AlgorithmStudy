#include <iostream>
#include <string>

//**������ : �� �ڸ� ���� 3�� ����̸� �� ���ڴ� 3�� ����̴�!
using namespace std;

int main() {
	int sum = 0;
	string s;
	cin >> s;
	for each (char c in s)
		sum += c - '0';
	sort(s.begin(), s.end());
	if (s[0] == '0' && sum % 3 == 0) {
		reverse(s.begin(), s.end());
		cout << s;
	}
	else
		cout << -1;
}