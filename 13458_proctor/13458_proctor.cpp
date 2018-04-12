#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int roomNum, tmp, main, sub;
	long long count = 0;
	vector<int> room;

	scanf("%d", &roomNum);
	for (int i = 0; i < roomNum; i++) {
		cin >> tmp;
		room.push_back(tmp);
	}
	cin >> main >> sub;

	for (int i = 0; i < room.size(); i++) {
		room[i] -= main;
		count++;
		if(room[i]>0)
			count += ceil(room[i]/(double)sub);
	}
	cout << count;
}