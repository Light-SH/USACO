/*
ID: wuyue171
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX = 1e6;

struct node {
	int begin;
	int end;
}s[MAX];


bool cmp(node p, node q){
	return p.begin < q.begin;
}

int main() {
	ofstream fout("milk2.out");
	ifstream fin("milk2.in");
	int n;
	fin >> n;
	for (int i = 0; i < n; i++) {
		fin >> s[i].begin >> s[i].end;
	}
	sort(s, s + n, cmp);     //对其排序
	int t1 = s[0].begin, t2 = s[0].end;   //t1存当前最左边，t2存当前最右边（可行的）
	int ans1 = 0, ans2 = 0;
	ans1 = max(ans1, t2 - t1);
	for (int i = 1; i < n; i++) {
		if (s[i].begin <= t2) {    //后一个的begin在前一个end之前
			t1 = min(t1, s[i].begin);     
			t2 = max(t2, s[i].end);
			ans1 = max(ans1, t2 - t1);
		}
		else {
			ans2 = max(ans2, s[i].begin - t2);  //要在t2没变之前计算
			t1 = s[i].begin;
			t2 = s[i].end;
			ans1 = max(ans1, t2 - t1);
		}
	}
	fout << ans1 << " " << ans2 << endl;
}
