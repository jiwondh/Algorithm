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

long long cache[101][10];

long long DP(int N, int here) {

	if (here == -1 || here == 10)
		return 0;

	if (N == 1)
		return 1;

	long long& ret = cache[N][here];

	if (ret != -1)
		return ret;

	long long before = DP(N - 1, here - 1);
	long long next = DP(N - 1, here + 1);

	long long cnt = (before + next) % 1000000000;

	return ret = cnt;

}

int main() {
	int N;
	cin >> N;

	long long cnt = 0;

	memset(cache, -1, sizeof(cache));

	for (int i = 1; i <= 9; i++) {
		cnt = cnt + DP(N, i);
		cnt = cnt % 1000000000;
	}
	cout << cnt;

	return 0;
}
