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
	string str;
	cin >> str;

	int strLength = str.length();
	int width = 2 * 2 + strLength + 3 * (strLength - 1);

	vector<vector<char> > frame(5, vector<char>(width, '.'));
	for (int i = 0; i < strLength; i++) {
		int standardIndex = (i * 4 + 3) - 1;
		// 3의 배수 위
		if ((i + 1) % 3 == 0) {
			frame[0][standardIndex] = '*';
			frame[1][standardIndex - 1] = '*';
			frame[1][standardIndex + 1] = '*';
			frame[2][standardIndex - 2] = '*';
			frame[2][standardIndex + 2] = '*';
			frame[3][standardIndex - 1] = '*';
			frame[3][standardIndex + 1] = '*';
			frame[4][standardIndex] = '*';
		} else {
			frame[0][standardIndex] = '#';
			frame[1][standardIndex - 1] = '#';
			frame[1][standardIndex + 1] = '#';
			frame[2][standardIndex - 2] = '#';
			frame[2][standardIndex + 2] = '#';
			frame[3][standardIndex - 1] = '#';
			frame[3][standardIndex + 1] = '#';
			frame[4][standardIndex] = '#';
		}
		frame[2][standardIndex] = str[i];
	}

	int i = 3;
	while (i <= strLength) {
		int standardIndex = ((i - 1) * 4 + 3) - 1;
		frame[2][standardIndex - 2] = '*';
		frame[2][standardIndex + 2] = '*';
		i = i + 3;
	}

	for (int i = 0; i < frame.size(); i++) {
		for (int j = 0; j < frame[i].size(); j++) {
			cout << frame[i][j];
		}
		cout << endl;
	}
	return 0;
}
