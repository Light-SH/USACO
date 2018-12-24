/*
ID: wuyue171
PROG: sprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <algorithm>

/*解题思路：建一个质数表，八位数开根号只用存四位数的质数表
失败原因：内存占用超过要求，
         尝试DFS递归并剪枝
*/

using namespace std;

/*仔细分析发现，只有2 3 5 7 四数可用*/
int ava[4] = { 2,3,5,7 };
int N;
ofstream fout("sprime.out");
ifstream fin("sprime.in");

bool isPrime(int x) {      //判断x是不是质数
	for (int i = 2; i <= sqrt(x); i++) {
		if (x%i == 0) 
			return false;
	}
	return true;
}

void DFS(int num, int depth) {    //num符合要求的数，depth为为当前迭代深度
	if (depth == N) {             //depth==N，输出当前符合要求的数
		fout << num << endl;
		return;
	}
	for (int i = 0; i < 10; i++) {      //迭代深度+1
		if(isPrime(num*10+i))
			DFS((num * 10 + i), depth + 1);
	}
}

int main() {
	fin >> N;
	for (int i = 0; i < 4; i++) {
		DFS(ava[i], 1);
	}
	
	return 0;
}




/*
bool prime[100000000];     //建一个质数表，是质数为1，不是质数为0
void prim() {
	int m = sqrt(100000000);
	for (int i = 1; i < 100000000; i++) {
		if (i == 1) prime[i] = false;
		if (i % 2 == 0) {
			prime[i] = false;
		}
		else {
			prime[i] = true;
		}
		if (i == 2) prime[i] = true;
	}
	for (int i = 3; i < m; i += 2) {
		if (prime[i]) {
			for (int j = i + i; j < 100000000; j += i)       //i是质数，那么i的倍数全不是质数
				prime[j] = false;
		}
	}
}

int main() {
	ofstream fout("sprime.out");
	ifstream fin("sprime.in");
	prim();                            //建立质数表
	int N;
	cin >> N;
	int start, end = 1;
	for (int i = 0; i < N; i++) {
		end *= 10;
	}
	start = end / 5 + 1;      //第一位为1时，1不是质数，从2***1开始

	for (int i = start; i < end; i += 2) {     //只看奇数
		int temp = i;
		int flag = 1;       //flag为1代表满足条件
		while (temp) {
			if (prime[temp]) {         //i是不是质数
				temp /= 10;
			}
			else {
				flag = 0;
				break;
			}
		}
		if (flag)
			fout << i << endl;
		
	}
	//system("pause");
	return 0;
}
*/
