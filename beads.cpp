/*
ID: wuyue171
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main() {
	ofstream fout("beads.out");
	ifstream fin("beads.in");
	int len = 0;
	string str =  "";
	fin >> len >> str;

	int max = 0;

	//从每个position
	for (int pos = 0; pos < len; pos++) {
		//从左到右
		int times1 = 0;
		char first = 0;
		int i = pos;
		while (times1 < len) {
			//找到第一个 非白 的beads是什么颜色
			if ('w' != str[i] && 0 == first) {
				first = str[i];
			}
			else if ('w' != str[i] && first != str[i]) {
				break;
			}

			i = (i + 1) % len;
			times1++;
		}

		//从右到左
		int times2 = 0;
		first = 0;
		i = (pos - 1 + len) % len;
		while (times2 < len - times1) {  //不存在相加超过len的情况
			//找第一个 非白 的颜色
			if ('w' != str[i] && 0 == first) {
				first = str[i];
			}
			else if ('w' != str[i] && first != str[i]) {
				break;
			}

			i = (i - 1 + len) % len;
			times2++;
		}
		if (times1 + times2 > max) {
			max = times1 + times2;
		}
	}
	fout << max << endl;
	return 0;
}
