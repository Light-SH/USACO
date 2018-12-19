/*
ID: wuyue171
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

/*解题思路：
有M个木板代表从第一个有牛的牛棚到最后一个有牛的牛棚之间，有M-1段可以不用被覆盖到，找出每个有牛的牛棚之间相隔距离，
找出其中最大的M-1个，这些不用覆盖，那么
最小木板长度就是最小有牛牛棚到最大有牛牛棚的长度减去这M-1个不用覆盖的长度
*/
using namespace std;

bool cmp(int a, int b) {   //降序
	return a > b;
}

int main() {
	ofstream fout("barn1.out");
	ifstream fin("barn1.in");
	int M, S, C;    //最多M块木板，一共S个牛棚，其中C个有牛
	fin >> M >> S >> C;

	int num[200];   //存哪些牛棚有牛的编号
	for (int i = 0; i < C; i++)
	{
		fin >> num[i];
	}
	sort(num, num + C);

	int ans = num[C - 1] - num[0] + 1;   //最大编号与最小编号间距离
	int length[200] = { 0 };  //存有牛牛棚间的距离
	int count = 0;
	for (int i = 0; i < C; i++) {
		if (i != 0) {
			length[count] = num[i] - num[i - 1] - 1;  //第i-1和第i编号牛棚间的距离,!!!!!!!不包括i-1和i，所以-1
			count++;
		}
	}
	sort(length, length + count, cmp);   //对距离从大到小排序
	for (int i = 0; i < M - 1; i++) {    //选择最大的M-1个，从ans中删除
		ans -= length[i];
	}
	fout << ans << endl;
	return 0;
}
