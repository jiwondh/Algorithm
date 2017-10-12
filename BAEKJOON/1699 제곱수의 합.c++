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

int cache[100001];

int DP(int N) {

	if (N == 1)
		return 1;
	if (N == 0)
		return 0;

	int& ret = cache[N];
	if (ret != -1)
		return ret;

	int cri = 1;
	int min = N;
	int x, y;

	while (cri <= (int) sqrt(N)) {
		int dif = N - (cri * cri);
		int temp = 0;
		if (dif == 0)
			temp = DP(dif) + 1;
		else
			temp = DP(cri * cri) + DP(dif);
		if (temp <= min) {
			min = temp;
			x = cri;
			y = dif;
		}
		cri++;
	}
	return ret = min;
}

int main() {
	int N;
	cin >> N;

	memset(cache, -1, sizeof(cache));

	cout << DP(N);

	return 0;
}
