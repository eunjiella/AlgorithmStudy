#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const int& a, const int& b) {
	if (a > 0 || b > 0) //하나이상 양수면 정상계산
		return (a > b);
	else return !(a > b); //음수끼리나 0이 포함된 비교는 반대로 계산
}

int main() {
	int num, tmp;
	vector<int> set, rearrange;

	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &tmp);
		set.push_back(tmp);
	}
	sort(set.begin(), set.end(), compare);

	for (int i = 0; i < num; i++) {
		if (i == num - 1 || set[i] == 0)
			rearrange.push_back(set[i]);

		else if (set[i] + set[i + 1] < set[i] * set[i + 1]) {
			rearrange.push_back(set[i] * set[i + 1]);
			i += 1;
		}
		else
			rearrange.push_back(set[i]);
	}
	tmp = 0;
	for (int i = 0; i < rearrange.size(); i++)
		tmp += rearrange[i];

	cout << tmp;

}