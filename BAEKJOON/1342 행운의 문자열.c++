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

int DP(char c, vector<char>& alpa, int depth, map<char, int>& m, int size) {

	if (m[c] == 0) {
		return 0;
	}

	m[c] = m[c] - 1;

	if (depth == size) {
		m[c] = m[c] + 1;
		return 1;
	}

	int result = 0;

	for (int i = 0; i < alpa.size(); i++) {
		if (alpa[i] != c) {
			result = result + DP(alpa[i], alpa, depth + 1, m, size);
		}
	}

	m[c] = m[c] + 1;

	return result;
}

int main() {
	string s;
	cin >> s;

	map<char, int> m;
	vector<char> alpa;
	pair<map<char, int>::iterator, bool> pr;

	for (int i = 0; i < s.length(); i++) {
		pr = m.insert(pair<char, int>(s[i], 1));
		if (pr.second != true) {
			m[s[i]] = m[s[i]] + 1;
		} else {
			alpa.push_back(s[i]);
		}
	}

	int result = 0;
	for (int i = 0; i < alpa.size(); i++) {
		result = result + DP(alpa[i], alpa, 1, m, s.length());
	}
	cout << result;

	return 0;
}
