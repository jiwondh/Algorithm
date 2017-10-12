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
	vector<pair<int, int> > coord(N);

	for (int i = 0; i < N; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		coord[i].first = x;
		coord[i].second = y;
	}

	sort(coord.begin(), coord.end());

	for (int i = 0; i < coord.size(); i++) {
		printf("%d %d\n", coord[i].first, coord[i].second);
	}

	return 0;
}
