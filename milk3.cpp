/*
ID: wuyue171
PROG: milk3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>

/*解题思路：经典的DFS倒水问题，根据被灌桶装满和原桶为空两种情况来进行DFS*/
using namespace std;

int A, B, C; 
int state[21][21][21], recorder[21] = { 0 };

void DFS(int a, int b, int c) {
	if (state[a][b][c]){   //此状态是否已被考虑过
		return;
	}         
	else {
		state[a][b][c] = 1;
	}
		
	if (a == 0 && !recorder[c])   //A桶为0，C桶内多少
		recorder[c] = 1;

	//c->a，C桶倒入A桶
	if (c >= A - a)      //C桶当前容量大于等于A桶剩余容量，
		DFS(A, b, c - A + a);
	else
		DFS(a + c, b, 0);
	//c->b
	if (c >= B - b)
		DFS(a, B, c - B + b);
	else
		DFS(a, b + c, 0);
	//b->a
	if (b >= A - a)
		DFS(A, b - A + a, c);
	else
		DFS(a + b, 0, c);
	//b->c
	if (b >= C - c)
		DFS(a, b - C + c, C);
	else
		DFS(a, 0, b + c);
	//a->b
	if (a >= B - b)
		DFS(a - B + b, B, c);
	else
		DFS(0, a + b, c);
	//a->c
	if (a >= C - c)
		DFS(a - C + c, b, C);
	else
		DFS(0, b, a + c);
}

int main() {
	ifstream fin("milk3.in");
	ofstream fout("milk3.out");

	fin >> A >> B >> C;
	DFS(0, 0, C);
	int count = 0;
	for (int i = 0; i <= C; i++) {       
		if (recorder[i]) {       //判断c从[O,C]哪个有解
			count++;
			if (count == 1) {   //是否是第一个
				fout << i;
			}
			else {
				fout << " " << i;
			}
		}
	}
	fout << endl;
	return 0;
}
