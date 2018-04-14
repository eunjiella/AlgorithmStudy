//sw expert academy
#include <iostream>
#include <vector>

using namespace std;
int map[20][20];
int possible(int i, int n, int x);
int possibleC(int j, int n, int x);

int main() {
	int num, n, x, res;
	vector<int> result;

	cin >> num;
	for (int tc = 0; tc < num; tc++) {//testcase
		cin >> n >> x;
		res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cin >> map[i][j];
			res += possible(i, n, x);
		}
		for (int i = 0; i < n; i++)
			res+=possibleC(i, n, x);
		result.push_back(res);
	}
	for (int i = 0; i < result.size(); i++)
		printf("#%d %d\n", i + 1, result[i]);

}
int possible(int i,int n,int x) {
	int count = 1, tmp=map[i][0];
	for (int j = 1; j < n; j++) {
		if (map[i][j]!=tmp) {
			if (abs(map[i][j] - tmp) > 1) return 0;
			if (map[i][j] > tmp) {
				if (count < x) return 0;
				count = 1;
				tmp = map[i][j];
			}
			else {
				for (int k = 0; k < x-1; k++) 
					if (map[i][j + k] != map[i][j + 1 + k]) return 0;
				tmp = map[i][j];
				j += x-1;
				count = 0;
			}
		}
		else count++;
	}
//	printf("---------row %d\n", i);
	return 1;
}
int possibleC(int j, int n, int x) {
	int count = 1, tmp = map[0][j];
	for (int i = 1; i < n; i++) {
		if (map[i][j] != tmp) {
			if (abs(map[i][j] - tmp) > 1) return 0;
			if (map[i][j] > tmp) { //작->커
				if (count < x) 	return 0;
				tmp = map[i][j];
				count = 1;
			}
			else { //커->작
				for (int k = 0; k < x-1; k++) 
					if (map[i + k][j] != map[i + 1 + k][j]) return 0;
				tmp = map[i][j];
				i += x-1;
				count = 0;
			}
		}
		else
			count++;
	}
	//printf("---------col %d\n", j);
	return 1;
}