/*
ID: wuyue171
PROG: ariprog
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
#define MAX 125010

int v[MAX];    //判断是否是p^2+q^2形式，1是0不是
int a[MAX];    //存数列
int n;

bool check(int length, int i) {   //i为首项，length为公差
	int start = a[i];
	for (int j = 0; j < n; j++) {   //判断n项，以a[i]为首项的等差数列是否满足平方和形式
		if (!v[start])
			return false;
		start += length;
	}
	return true;
}

int main() {
	ifstream fin("ariprog.in");
	ofstream fout("ariprog.out");

	int M = 0;
	fin >> n >> M;
	int count = 0;        //数组长度
	for (int i = 0; i <= M; i++) {
		for (int j = 0; j <= M; j++) {
			if (!v[i*i + j*j]) {      //判断数组中此时为0
				a[count] = i*i + j*j;
				v[i*i + j*j] = 1;
				count++;
			}
		}
	}
	sort(a, a + count);     //将数列a排序,此时a中元素为递增的平方和形式数列
	int maxLength = (a[count - 1] - a[0]) / (n - 1);    //公差的最大值不会超过maxLength
	int flag = 0;            
	for (int length = 1; length <= maxLength; length++) {    //公差[1,maxLength]
		for (int i = 0; i < count; i++) {                    //首项[0,count]
			if (a[i] + (n - 1)*length > a[count - 1])        //剪枝
				break;
			if (check(length, i)) {
				flag = 1;
				fout << a[i] << " " << length << endl;
			}
		}
	}
	if (!flag)
		fout << "NONE" << endl;

	return 0;
}
