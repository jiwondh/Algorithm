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

int N, M;

vector<vector<int> > paper(501, vector<int>(501, 0));
int visited[501][501];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

bool isOutSide(pair<int, int> here) {
	int hereY = here.first;
	int hereX = here.second;

	if (hereY < 0 || hereY > N - 1 || hereX < 0 || hereX > M - 1)
		return true;
	else
		return false;
}

int DFS(pair<int, int> here, int cnt) {

	int hereY = here.first;
	int hereX = here.second;
	int herePoint = paper[hereY][hereX];


	if (cnt == 4) {
		return herePoint;
	}

	visited[hereY][hereX] = true;

	int max = 0;

	for (int i = 0; i < 4; i++) {

		int thereY = hereY + dy[i];
		int thereX = hereX + dx[i];
		pair<int, int> there = make_pair(thereY, thereX);

		if (!isOutSide(there) && !visited[thereY][thereX]) {

			int temp = DFS(there, cnt + 1);
			if (max < temp)
				max = temp;
		}
	}
	visited[hereY][hereX] = false;
	return max + herePoint;
}

bool isPossible(pair<int, int> here, int i) {
	int hereY = here.first;
	int hereX = here.second;

	switch (i) {
	case 0:
		if (hereY == N - 1 || hereX == 0 || hereX == M - 1)
			return false;
		else
			return true;
	case 1:
		if (hereY == 0 || hereX == 0 || hereX == M - 1)
			return false;
		else
			return true;
	case 2:
		if (hereX == M - 1 || hereY == 0 || hereY == N - 1)
			return false;
		else
			return true;
	case 3:
		if (hereX == 0 || hereY == 0 || hereY == N - 1)
			return false;
		else
			return true;
	default:
		return true;
	}
}
int ReturnSum(pair<int, int> here, int i) {
	int hereY = here.first;
	int hereX = here.second;

	switch (i) {
	case 0:
		return paper[hereY][hereX - 1] + paper[hereY][hereX + 1]
				+ paper[hereY + 1][hereX];
	case 1:
		return paper[hereY][hereX - 1] + paper[hereY][hereX + 1]
				+ paper[hereY - 1][hereX];
	case 2:
		return paper[hereY - 1][hereX] + paper[hereY + 1][hereX]
				+ paper[hereY][hereX + 1];
	case 3:
		return paper[hereY - 1][hereX] + paper[hereY + 1][hereX]
				+ paper[hereY][hereX - 1];
	default:
		return 0;
	}
}
int BFS(pair<int, int> here) {

	int hereY = here.first;
	int hereX = here.second;
	int herePoint = paper[hereY][hereX];

	int max = 0;
	for (int i = 0; i < 4; i++) {
		if (!isPossible(here, i))
			continue;
		int sum = herePoint + ReturnSum(here, i);
		if (max < sum)
			max = sum;
	}
	return max;
}
int main() {

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &paper[i][j]);
		}
	}

	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			int temp = DFS(make_pair(i, j), 1);
			int temp2 = 0;
			temp2 = BFS(make_pair(i, j));

			if (max < temp)
				max = temp;
			if (max < temp2)
				max = temp2;
		}
	}
	printf("%d", max);

	return 0;
}
