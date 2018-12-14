/*
ID: wuyue171
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

int daysofmonth[13][2] = { {0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31} };

bool isLeapYear(int x) {  //是否是闰年
	return ((x % 400 == 0) || (x % 4 == 0 && x % 100 != 0));
}

int main() {
	ofstream fout("friday.out");
	ifstream fin("friday.in");
	int n;   //输入n年
	fin >> n;
	int days = 0;  //距离1900.1.1多少天
	int d[8];
	for (int i = 1; i <= 7; i++) {
		d[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		int t = isLeapYear(1900 + i);  //判断1900+i是否闰年
		for (int j = 1 ; j <= 12; j++) {  //第1900+i年的第j个月
			d[(days + 12) % 7 + 1]++;  //第一次判断1900.1.13是周几，随后递加1个月
			days += daysofmonth[j][t];
		}
	}
	//cout << isLeapYear(1900);
	//system("pause");
	fout << d[6] << " " << d[7] << " " << d[1] << " " << d[2] << " " << d[3] << " " << d[4] << " " << d[5] << endl;
	return 0;
}
