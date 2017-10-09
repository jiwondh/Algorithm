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

	map<string, int> m;

	vector<int> exit(N);

	for (int i = 0; i < N; i++) {
		string car;
		cin >> car;
		m.insert(pair<string, int>(car, i));
	}

	for (int i = 0; i < N; i++) {
		string car;
		cin >> car;
		exit[i] = m[car];
	}

	int cnt = 0;

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (exit[i] > exit[j]) {
				cnt++;
				break;
			}
		}
	}

	cout << cnt;
	return 0;
}
