#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <stack>
#include <functional>
#include <math.h>

using namespace std;

int infoMul[10] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000,
		100000000, 1000000000 };

int main() {

	vector<string> color;
	for (int i = 0; i < 3; i++) {
		string str;
		cin >> str;
		color.push_back(str);
	}
	map<string, string> infoValue;

	infoValue.insert(pair<string, string>("black", "0"));
	infoValue.insert(pair<string, string>("brown", "1"));
	infoValue.insert(pair<string, string>("red", "2"));
	infoValue.insert(pair<string, string>("orange", "3"));
	infoValue.insert(pair<string, string>("yellow", "4"));
	infoValue.insert(pair<string, string>("green", "5"));
	infoValue.insert(pair<string, string>("blue", "6"));
	infoValue.insert(pair<string, string>("violet", "7"));
	infoValue.insert(pair<string, string>("grey", "8"));
	infoValue.insert(pair<string, string>("white", "9"));

	string temp = infoValue[color[0]] + infoValue[color[1]];
	long long result = (long long)atoi(temp.c_str())
			* infoMul[atoi(infoValue[color[2]].c_str())];
	cout << result;

}

