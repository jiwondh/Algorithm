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
#include <bitset>

using namespace std;

int main() {
	vector<vector<char> > word(5, vector<char>(15, 0));

	for (int i = 0; i < 5; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			word[i][j] = str[j];
		}

	}

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			if (word[j][i] != 0)
				cout << word[j][i];
		}
	}
	return 0;
}
