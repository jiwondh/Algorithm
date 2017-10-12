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

	if (N < 3)
		return -1;
	else if (N == 3 || N == 5)
		return 1;

	int& ret = cache[N];
	if (ret != 0)
		return ret;

	int a = DP(N - 5);
	int b = DP(N - 3);

	if (a == -1 && b == -1)
		return ret = -1;
	else if (a == -1 && b != -1) {
		return ret = b + 1;
	} else if (b == -1 && a != -1) {
		return ret = a + 1;
	} else if (a < b) {
		return ret = a + 1;
	} else {
		return ret = b + 1;
	}

}

int main() {
	int N;
	cin >> N;

	cout << DP(N);

	return 0;
}
