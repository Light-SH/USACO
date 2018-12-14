/*
ID: wuyue171
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ofstream fout("ride.out");
	ifstream fin("ride.in");
	string a, b;
	while (fin >> a >> b) {
		//字符串最长6位，26^6不超出int范围
		int suma, sumb;
		suma = sumb = 1;
		for (int i = 0; i < a.length(); i++) {
			suma *= (a[i] - 'A' + 1);
		}
		for (int i = 0; i < b.length(); i++) {
			sumb *= (b[i] - 'A' + 1);
		}
		if (suma % 47 == sumb % 47)
			fout << "GO" << endl;
		else
			fout << "STAY" << endl;
	}
	return 0;
}
