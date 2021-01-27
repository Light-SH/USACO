/*
ID: wuyue171
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

bool isPal(char s[]) {         //是否是回文
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
		int temp = num%base;      //temp为最低位,先存最低位，再翻转
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
	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");
	int _base;
	fin >> _base;
	for (int i = 1; i < 300; i++) {
		char s1[20] = "";
		base(i*i, _base, s1);
		if (isPal(s1)) {
			char s2[20] = "";
			base(i, _base, s2);
			fout << s2 << " " << s1 << endl;
		}
	}
	//system("pause");
	return 0;
	/*int num = 90; int b = 13;
	char s[50]=" ";
	base(num, b, s);
	cout << s << endl;
	system("pause");*/
}
