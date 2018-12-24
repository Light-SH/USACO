/*
ID: wuyue171
PROG: numtri
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
/*
a |= 0x20;		 turn on bit 0x20   置1
a &= ~0x20;		 turn off bit 0x20  清0
a ^= 0x20;		 toggle bit 0x20    翻转
if(a & 0x20)     判断
*/
#define Max 1005
/*解题思路：   可从下往上推，每一个*都是[自身+max（正下方，右下方）],由此最上方的数就是max
*
**
***
****
*****
*/

using namespace std;

int a[Max][Max];

int main() {
	ofstream fout("numtri.out");
	ifstream fin("numtri.in");
	int row;
	fin >> row;
	for (int i = 1; i <= row; i++) {        //初始化
		for (int j = 1; j <= i; j++) {
			fin >> a[i][j];
		}
	}
	for (int i = row - 1; i > 0; i--) {      //从倒数第二行开始
		for (int j = 1; j <= i; j++) {
			a[i][j] = a[i][j] + max(a[i + 1][j], a[i + 1][j + 1]);   //当前从下往上的max
		}
	}
	fout << a[1][1] << endl;
	return 0;
}
