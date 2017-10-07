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
	int N;
	cin >> N;

	vector<int> student(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> student[i];
	}

	int total, sub;
	cin >> total >> sub;

	long long cnt = 0;

	for (int i = 0; i < N; i++) {
		student[i] = student[i] - total;
		cnt++;

		if (student[i] > 0) {

			int quotient = 1;
			int remainder = 0;
			while (quotient != 0) {
				quotient = student[i] / sub;
				remainder = student[i] % sub;
				student[i] = remainder;
				cnt = cnt + quotient;
				if (quotient == 0 && remainder != 0)
					cnt = cnt + 1;
			}
		}
	}
	cout << cnt;

	return 0;
}
