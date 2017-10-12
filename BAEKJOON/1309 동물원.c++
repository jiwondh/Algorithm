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

#define X 0
#define L 1
#define R 2

int cache[100001][3];

int DP(int N, int state) {

	if (N == 1) {
		return 1;
	}

	int& ret = cache[N][state];
	if (ret != -1) {
		return ret;
	}

	int result = 0;
	switch (state) {
	case X:
		result = DP(N - 1, X) + DP(N - 1, L) + DP(N - 1, R);
		break;
	case L:
		result = DP(N - 1, X) + DP(N - 1, R);
		break;
	case R:
		result = DP(N - 1, X) + DP(N - 1, L);
		break;
	default:
		break;
	}
	return ret = result % 9901;
}

int main() {
	int N;
	cin >> N;

	memset(cache, -1, sizeof(cache));

	cout << (DP(N, X) + DP(N, L) + DP(N, R)) % 9901;
	return 0;
}
