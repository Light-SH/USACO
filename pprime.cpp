/*
ID: wuyue171
PROG: pprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stdio.h>

/*解题思路：为避免超时，先生成回文数，再判断是否是质数*/
using namespace std;

ifstream fin("pprime.in");
ofstream fout("pprime.out");

bool isPrime(int x) {      //判断是否是 质数
						   //if (x % 2 == 0)
						   //return false;
	for (int i = 3; i <= sqrt(x); i++) {
		if (x%i == 0)
			return false;
	}
	return true;
}

void CheckValid(int begin, int end, int target_num) {
	if (target_num >= begin && target_num <= end && isPrime(target_num))
		fout << target_num << endl;
}

bool isPal(int x) {       //判断是否是 回文数
	int i;
	char s[10] = "";

	int first = x % 10;
	if (first % 2 == 0)     //为简化质数判断，最低位即开头为偶数的回文必不是质数
		return false;

	for (i = 0; x > 0; i++) {   //将整数i变为char s[]
		int temp = x % 10;
		x /= 10;
		s[i] = temp + '0';
	}
	//sprintf(s, "%d", x);    //整数转换为字符串

	int len = strlen(s);      //此时为逆序
	for (int j = 0; j < len; j++) {
		if (s[j] != s[len - j - 1])     //若为回文数，头尾依次相等
			return false;
	}
	return true;
}

int main() {

	int begin, end;
	fin >> begin >> end;
	/*
	for (int i = begin; i <= end; i++) {
		if (isPal(i)) {
			if(isPrime(i))
				fout << i << endl;
		}
			
	}*/
	//system("pause");

	//Handle special case
	//3呢
	if (begin == 5) fout << 5 << endl;
	if (begin <= 7 && end >= 7) fout << 7 << endl;
	if (begin <= 11 && end >= 11) fout << 11 << endl;
	//Handle regular case;
	if (begin <= 999 && end >= 101) {
		for (short a = 1; a <= 9; a += 2) {
			for (short b = 0; b <= 9; b++) {
				CheckValid(begin, end, a * 101 + b * 10);
			}
		}
	}
	if (begin <= 99999 && end >= 10001) {
		for (short a = 1; a <= 9; a += 2) {
			for (short b = 0; b <= 9; b++) {
				for (short c = 0; c <= 9; c++) {
					CheckValid(begin, end, a * 10001 + b * 1010 + c * 100);
				}
			}
		}
	}
	if (begin <= 9999999 && end >= 1000001) {
		for (short a = 1; a <= 9; a += 2) {
			for (short b = 0; b <= 9; b++) {
				for (short c = 0; c <= 9; c++) {
					for (short d = 0; d <= 9; d++) {
						CheckValid(begin, end, a * 1000001 + b * 100010 + c * 10100 + d * 1000);
					}
				}
			}
		}
	}
	
	return 0;
}
