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

int cache[15];

int dp(vector<pair<int, int> >& counsel, int today, int N) {
	int days = counsel[today].first;
	int point = counsel[today].second;

	int& ret = cache[today];

	if (ret != -1)
		return ret;

	if (today == N - 1 && days == 1) {
		return ret = counsel[today].second;
	} else if (today > N - 1) {
		return 0;
	}

	int maxIncome;

	if (days + today > N)
		maxIncome = 0;
	else if (days + today == N) {
		maxIncome = counsel[today].second;
	} else
		maxIncome = dp(counsel, today + days, N) + point;

	for (int i = 1; i < days; i++) {
		int result = dp(counsel, today + i, N);
		if (maxIncome < result)
			maxIncome = result;
	}

	return ret = maxIncome;

}
int main() {
	int N;
	cin >> N;

	vector<pair<int, int> > counsel;
	for (int i = 0; i < N; i++) {
		int days, point;
		cin >> days >> point;
		counsel.push_back(make_pair(days, point));
	}

	memset(cache, -1, sizeof(cache));

	cout << dp(counsel, 0, N);
	return 0;
}
