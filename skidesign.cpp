/*
ID: wuyue171
PROG: skidesign
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

/*解题思路：
找出初始最高山峰，由题意可知，最高山峰只可能降低，遍历枚举0-max，不断比较最高高度为多少时，cost最小
*/
using namespace std;

int main() {
	ofstream fout("skidesign.out");
	ifstream fin("skidesign.in");
	int N;   //N座山峰
	fin >> N;
	int a[1100];
	int max = 0;   //最高山峰
	int cost = 1000000;   //花费
	for (int i = 0; i < N; i++) {
		fin >> a[i];
		if (max < a[i]) max = a[i];
	}
	for (int i = 0; i <= max; i++) {   //枚举哪个最高高度，花费最少
		int cur = 0;
		for (int j = 0; j < N; j++) {  //对每一座山峰而言
			if (a[j] < i - 17)     //当前山峰比最高山峰-17还低，表示需要提升高度
				cur += (i - 17 - a[j])*(i - 17 - a[j]);
			if (a[j] > i)          //当前山峰比预计的最高山峰还高，需要降低高度
				cur += (a[j] - i)*(a[j] - i);
		}
		cost = cost > cur ? cur : cost;
	}
	fout << cost << endl;
	return 0;
}
