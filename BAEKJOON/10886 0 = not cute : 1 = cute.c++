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

	vector<int> opinion(2, 0);

	for (int i = 0; i < N; i++) {
		int op;
		cin >> op;
		opinion[op] = opinion[op] + 1;
	}

	if (opinion[0] > opinion[1]) {
		cout << "Junhee is not cute!";
	} else {
		cout << "Junhee is cute!";
	}
	return 0;
}
