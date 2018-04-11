#include <iostream>
#include <string>
#include <math.h>

#define gearNum 4
#define compNum 8
using namespace std;

typedef struct Gear_ {
	int top=0;
	int comp[compNum];
	int direction;
	int right() {
		return comp[(top + 2)%8];
	}
	int left() {
		return comp[(top + 6)%8];
	}
	/*void print() {
		int n = 0;
		printf("*%d*", direction);
		for (int i = top; n<compNum; i++) {
			printf("%d ", comp[i%compNum]);
			n++;
		}
		printf("&%d&\n",top);
	}*/
}Gear;

Gear gear[gearNum];
void rotate(int g, int d);
void operate(int g, int d);
void init();
int calculate();
int getTop(Gear g);

void main() {
	string s[gearNum];
	int caseNum,g,d;
	for (int i = 0; i < gearNum; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < gearNum; i++) {
		for (int j = 0; j < compNum; j++) {
			gear[i].comp[j] = s[i][j] - '0';
		}
	}
	scanf("%d", &caseNum);
	for (int i = 0; i < caseNum; i++) {
		scanf("%d %d", &g, &d);
		init();
		operate(g-1, d);
		   
/*		printf("*\n");
		gear[0].print();
		gear[1].print();
		gear[2].print();
		gear[3].print();
		printf("\n");*/
	}
	printf("%d\n", calculate());
	
}
void init() {
	for (int i = 0; i < gearNum; i++)
		gear[i].direction = 0;
}
void rotate(int g, int d) {
	
	gear[g].top = (gear[g].top -d +compNum)%compNum;
	gear[g].direction = d;
}
void operate(int g,int d) {
	int p[3];
	for(int i=0;i<gearNum-1;i++)
		p[i] = (gear[i].right() == gear[i + 1].left()) ? 1 : 0;

	rotate(g,d);
	for (int i = g; i<gearNum-1; i++) {
		if (p[i])
			break;
		rotate(i+1, gear[i].direction*(-1));
	}
	for (int i = g; i > 0; i--) {
		if (p[i-1])
			break;
		rotate(i-1, gear[i].direction*(-1));
	}
}
int getTop(Gear g) {
	return g.comp[g.top];
}
int calculate() {
	int sum = 0;
	for (int i = 0; i < gearNum; i++) {
		if (getTop(gear[i]))
			sum += pow(2, i);
	}
	return sum;
}