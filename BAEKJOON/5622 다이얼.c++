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

int matchDial(char c) {

	if ('A' <= c && c <= 'C')
		return 2;
	else if ('D' <= c && c <= 'F')
		return 3;
	else if ('G' <= c && c <= 'I')
		return 4;
	else if ('J' <= c && c <= 'L')
		return 5;
	else if ('M' <= c && c <= 'O')
		return 6;
	else if ('P' <= c && c <= 'S')
		return 7;
	else if ('T' <= c && c <= 'V')
		return 8;
	else if ('W' <= c && c <= 'Z')
		return 9;
	else
		return 0;
}

int main() {
	string str;
	cin >> str;

	vector<int> alphabet(26, 0);

	for (int i = 0; i < 26; i++) {
		alphabet[i] = matchDial(i + 65);
	}

	int cnt = 0;

	for (int i = 0; i < str.length(); i++) {
		cnt = cnt + alphabet[str[i] - 65] + 1;
	}

	cout << cnt;

	return 0;
}
