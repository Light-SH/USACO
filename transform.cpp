/*
ID: wuyue171
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
const static int MAX = 12;
using namespace std;

char before[MAX][MAX];
char after[MAX][MAX];

int n, ans = 7;   //初始假定找不到

void cmp(int x) {    //比较
	bool flag = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (before[i][j] != after[i][j]) {
				flag = false;
			}
		}
	}
	if (flag)
		ans = min(ans, x);
}

void roation90() {    //旋转90
	char temp[MAX][MAX];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) 
			temp[j][n - i - 1] = before[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			before[i][j] = temp[i][j];
}

void reflection() {   //镜像
	char temp[MAX][MAX];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			temp[i][n - j - 1] = before[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			before[i][j] = temp[i][j];
}

int main() {
	//初始化
	ofstream fout("transform.out");
	ifstream fin("transform.in");
	fin >> n;
	for (int i = 0; i < n; i++)
		fin >> before[i];
	for (int i = 0; i < n; i++) {
		fin >> after[i];
	}

	cmp(6);         //#6 no change
	roation90();    //#1 旋转90
	cmp(1);
	roation90();    //#2 旋转180
	cmp(2);
	roation90();    //#3 旋转270
	cmp(3);

	roation90();    //#4 翻转
	reflection();
	cmp(4);
	                //#5 组合
	for (int i = 1; i <= 3; i++) {
		roation90();
		cmp(5);
	}

	fout << ans << endl;

	return 0;
}
