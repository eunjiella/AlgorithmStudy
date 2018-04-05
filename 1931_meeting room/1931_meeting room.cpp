#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct sch {
	int start, end;

	sch(int s, int e) {
		start = s;
		end = e;
	}
	bool operator <(const sch &S) {
		if (end == S.end)
			return start < S.start; //빨리 시작하는게 높은 우선순위
		return end < S.end; //빨리 끝나는게 높은 우선순위
	}
};
int main() {
	int num, tmp1, tmp2;
	vector<sch> meetings;

	scanf("%d", &num);
	for (int i = 0; i<num; i++) {
		scanf("%d %d", &tmp1, &tmp2);
		meetings.push_back(sch(tmp1, tmp2));
	}
	sort(meetings.begin(), meetings.end());

	tmp1 = meetings[0].end;
	tmp2 = 1;
	for (int i = 1; i < num; i++) {
		if (tmp1 > meetings[i].start)
			continue;
		else {
			tmp2++;
			//printf("*(%d %d)\n", meetings[i].start, meetings[i].end);
			tmp1 = meetings[i].end;
		}
	}
	printf("%d", tmp2);
}