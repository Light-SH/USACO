/*
ID: wuyue171
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

int main() {
	ofstream fout("gift1.out");
	ifstream fin("gift1.in");
	string name[15];  //用于存所有人姓名
	int NP;   //共NP个人
	while (fin >> NP) {
		map<string, int> m;  //字典，string表示姓名，int表示money
		for (int i = 0; i < NP; i++) {  //初始化
			fin >> name[i];
			m[name[i]] = 0;
		}
		string person;    //当前人
		int money, num, avg;   //有多少钱，分给几个人， 平均每人多少
		while (fin >> person >> money >> num) {
			if (num == 0)
				avg = 0;
			else
				avg = money / num;
			m[person] = m[person] - avg*num;

			for (int i = 0; i < num; i++) {
				string rec;
				fin >> rec;
				m[rec] += avg;
			}
		}
		for (int i = 0; i < NP; i++) {
			fout << name[i] << " " << m[name[i]] << endl;
		}
	}
	return 0;
}
