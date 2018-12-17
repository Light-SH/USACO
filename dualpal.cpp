/*
ID: wuyue171
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

bool isPal(char s[]) {
	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		if (s[i] != s[len - i - 1])
			return false;
	}
	return true;
}

void base(int num, int base, char ans[]) {
	int i;
	for (i = 0; num != 0; i++) {
		int temp = num%base;    //temp为最低位,先存最低位，再翻转
		num /= base;
		if (temp > 9)
			ans[i] = temp - 10 + 'A';
		else
			ans[i] = temp + '0';
	}
	for (int j = 0; j < i / 2; j++)
		swap(ans[j], ans[i - j - 1]);
}

int main() {
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");
	
	int N;       //N个数
	fin >> N;
	int S;       //比S大
	fin >> S;  
	int n = 0;   //有几个
	
	for (int i = S+1 ; n < N; i++) {   //比S大
		int flag = 0;
		for (int j = 2; j < 11; j++) {    //2-10进制
			char s[100] = "";
			base(i, j, s);         //数字i转化为j进制，存入s[]
			if (isPal(s)){
				flag++;
			}
		}
		if (flag >= 2) {
			n++;
			fout << i << endl;
		}
	}
	return 0;
}
