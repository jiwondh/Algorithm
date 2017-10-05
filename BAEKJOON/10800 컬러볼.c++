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
	scanf("%d", &N);

	vector<pair<int, int> > ball, balltemp;
	vector<int> colorBallSum(N + 1, 0);
	map<pair<int, int>, int> score;

	for (int i = 0; i < N; i++) {
		int color, size;
		scanf("%d %d", &color, &size);
		ball.push_back(make_pair(size, color));
	}
	balltemp = ball;
	sort(ball.begin(), ball.end());

	int beforeSizeSum = 0;
	int thisSizeSum = 0;
	int beforeSize = ball[0].first;

	for (int i = 0; i < ball.size(); i++) {
		int thisSize = ball[i].first;
		int thisColor = ball[i].second;

		if (beforeSize != thisSize)
			beforeSizeSum = thisSizeSum;

		score.insert(
				make_pair(make_pair(thisSize, thisColor),
						beforeSizeSum - colorBallSum[thisColor]));
		colorBallSum[thisColor] = colorBallSum[thisColor] + thisSize;
		thisSizeSum = thisSizeSum + thisSize;
		beforeSize = thisSize;
	}

	for (int i = 0; i < N; i++) {
		int thisSize = balltemp[i].first;
		int thisColor = balltemp[i].second;
		printf("%d\n", score[make_pair(thisSize, thisColor)]);
	}
	return 0;
}
