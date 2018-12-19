/*
ID: wuyue171
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

struct farmer {
	int cost;     //每单位价格
	int units;    //有多少单位
}fa[5000];

bool cmp(farmer a, farmer b) {
	return a.cost < b.cost;
}

int main() {
	ofstream fout("milk.out");
	ifstream fin("milk.in");
	int totalPrice = 0;
	int totalMilk, numofF;     //总牛奶需求量，farmer总数
	fin >> totalMilk >> numofF;
	for (int i = 0; i < numofF; i++) {
		fin >> fa[i].cost >> fa[i].units;
	}
	sort(fa, fa + numofF, cmp);  //根据cost排序，升序
	int curMilk = 0;   //目前已买
	while (curMilk != totalMilk) {
		for (int i = 0; i < numofF; i++) {
			if (fa[i].units < (totalMilk - curMilk)) {   //剩余要买的比当前farmer的多
				curMilk += fa[i].units;
				totalPrice += fa[i].units*fa[i].cost;
			}
			else {   //剩余要买的比当前farmer的少
				totalPrice += (totalMilk - curMilk)*fa[i].cost;
				totalMilk = curMilk;
			}
		}
	}
	fout << totalPrice << endl;
}
