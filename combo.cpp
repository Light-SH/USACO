/*
ID: wuyue171
PROG: combo
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int n;   //密码锁1-n

bool check(int a, int b) {
	if (abs(a - b) % n <= 2)
		return 1;
	if (abs(a - b) % n >= n - 2)
		return 1;
	return 0;
}

int main() {
	ofstream fout("combo.out");
	ifstream fin("combo.in");

	fin >> n;
	int a[3], b[3];  //farmer定义a,lock master定义b
	for (int i = 0; i < 3; i++)
		fin >> a[i];
	for (int i = 0; i < 3; i++)
		fin >> b[i];
	int num[101][101][101] = { 0 };     //防止出现重复，若为1表示已被考虑
	int count = 0;   //计算次数

	for (int i = 1; i <= n; i++) {   //第一位
		for (int j = 1; j <= n; j++) {  //第二位
			for (int k = 1; k <= n; k++) {   //第三位
				if (num[i][j][k] == 0) {
					if ((check(i, a[0]) && check(j, a[1]) && check(k, a[2])) ||
						(check(i, b[0]) && check(j, b[1]) && check(k, b[2]))) {
						count++;
						num[i][j][k] = 1;
					}
				}
			}
		}
	}
	fout << count << endl;
}
