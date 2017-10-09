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

	vector<int> outlet(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> outlet[i];
	}

	sort(outlet.begin(), outlet.end(), greater<int>());

	if (outlet[0] == 1) {
		cout << 1;
		return 0;
	}

	queue<int> q;

	int total = N - 1;

	int k = 0;

	q.push(0);

	int result = 0;

	while (total > 0) {
		k = q.front();
		q.pop();
		for (int i = 1; i <= outlet[k]; i++) {
			if (total <= 0) {
				result++;
				total--;
			} else {
				total--;
				q.push(N - total - 1);
			}
		}
		k++;
	}
	while (!q.empty()) {
		result = result + outlet[q.front()];
		q.pop();
	}
	cout << result;
	return 0;
}

/* 아래와 같은 간단한 방법도 있음..*/

//int main() {
//	int N;
//	cin >> N;
//
//	int result = 1;
//
//	for (int i = 0; i < N; i++) {
//		int outlet;
//		cin >> outlet;
//		result = result + (outlet - 1);
//	}
//
//	cout << result;
//
//	return 0;
//}

