/*
ID: wuyue171
PROG: wormhole
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
#define MAX_N 12
 //全局变量初始值为0
int n;                               //虫洞个数
int X[MAX_N + 1], Y[MAX_N + 1];      //用于存每个虫洞的坐标
int partner[MAX_N + 1];              //存 配对的
int next_on_right[MAX_N + 1];        //存虫洞i的正右方的最近虫洞位置j或0

bool cycle_exists() {   //是否存在循环,从某个wormhole到其配对wormhole，再到next_on_rigth，再到其配对虫洞
	for (int start = 1; start <= n; start++) {   //是否存在从start开始的循环
		int pos = start;
		for (int count = 0; count < n; count++) {
			pos = next_on_right[partner[pos]];   //或某跳后，右边没有wormhole,表示没有循环，此时pos=0
		}
		if (pos != 0) return true;
	}
	return false;
}

int solve() {    //为所有虫洞配对,计数所有可行解
	//找到第一个unpaired虫洞
	int i,total = 0;
	for (i = 1; i <= n; i++) {
		if (partner[i] == 0)   //i没有配对，跳出for循环
			break;
	}

	//所有wormhole配对完毕，此时i>n
	if (i > n) {
		if (cycle_exists()) return 1;
		else return 0;
	}

	for (int j = i + 1; j <= n; j++) {
		if (partner[j] == 0) {       //j也没有配对,与i配对
			//将i&j配对后，递归执行将其他wormhole配对
			partner[i] = j;
			partner[j] = i;
			total += solve();
			partner[i] = partner[j] = 0;    //在所有递归，虫洞配对完成后，设为初值，来考虑下一种情况
		}
	}
	return total;

}

int main() {
	ifstream fin("wormhole.in");
	fin >> n;
	for (int i = 1; i <= n; i++) {
		fin >> X[i] >> Y[i];
	}
	fin.close();

	//设置next_on_right[i]，找出i紧邻的正右wormhole
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (X[j] > X[i] && Y[i] == Y[j]) {   //j在i正右边
				if (next_on_right[i] == 0 ||     //如果之前没有找到或已找到一个但j距离更近
					X[j] - X[i] < X[next_on_right[i]] - X[i])
					next_on_right[i] = j;
			}
		}
	}

	ofstream fout("wormhole.out");
	fout << solve() << endl;
	fout.close();
	return 0;
}

