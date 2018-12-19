/*
ID: wuyue171
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int hash1[10];

bool check(int x) {    //x中若含额外数字，返回0,全是规定数字，返回1
	while (x) {
		if (!hash1[x % 10]) {
			return 0;
		}
		x /= 10;
	}
	return 1;
}

int main() {
	ofstream fout("crypt1.out");
	ifstream fin("crypt1.in");
	
	int n;    //用到n个数
	fin >> n;
	int t;
	for (int i = 0; i < n; i++) {   //用到的数字在hash中为1
		fin >> t;
		hash1[t] = 1;
	}
	int count = 0;    //解法数
	for (int i = 100; i < 1000; i++) {   //第一行乘数，三位数
		if (!check(i)) {        //若i中包含不在规定中数字，开始找下一个
			continue;
		}
		for (int j = 10; j < 100; j++) {  //第二行乘数，二位数
			if (!check(j)) {    //第二行都是
				continue;
			}
			int m = i*j;       
			if (!check(m)|| (m>10000) ) {     //两数相乘数字也在规定数字中,且是个四位数
				continue;
			}
			int t1 = i*(j % 10);   //第一乘数 * 第二乘数的个位
			int t2 = i*(j / 10);   //第一乘数 * 第二乘数的十位
			if (!check(t1) || !check(t2) || (t1>1000) || (t2>1000)) {   //是否数字都在规定中,且都是三位数
				continue;
			}
			count++;
		}
	}
	fout << count << endl;
	return 0;
}
