/*
ID: wuyue171
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

char dict[5000][15];   //存字典中姓名

int function[26] = { 2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0 };

int main() {
	ifstream fin("dict.txt");
	ifstream in("namenum.in");
	ofstream fout("namenum.out");

	char num[15];  //存要比较的输入
	bool flag = 0; //有没有
	int count = 0;
	while (fin >> dict[count])   //输入字典
		count++;
	in >> num;     //要比较的编号
	for (int i = 0; i < count; i++) {
		int FALG = 1;
		if (strlen(num) != strlen(dict[i]))
			continue;          //若字符长度不匹配，则终止找下一个
		for (int j = 0; j < strlen(dict[i]); j++) {
			if (function[dict[i][j] - 'A'] == num[j] - '0')
				continue;      //匹配每一个字符，匹配则试下一个
			else {             //不匹配，终止j的for循环，重新回到i的for循环
				FALG = 0;
				break;
			}
		}
		if (FALG) {   //找到了一个
			flag = 1;
			fout << dict[i] << endl;
		}
	}
	if (!flag) {    //一直没找到
		fout << "NONE" << endl;
	}
	return 0;
}
