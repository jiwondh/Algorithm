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

pair<int, int> NextDirection(pair<int, int> here, int direction) {
	int hereX = here.second;
	int hereY = here.first;
	switch (direction) {
	case 0:
		return make_pair(hereY, hereX - 1);
	case 1:
		return make_pair(hereY - 1, hereX);
	case 2:
		return make_pair(hereY, hereX + 1);
	case 3:
		return make_pair(hereY + 1, hereX);
	}

	return make_pair(hereY, hereX);
}
pair<int, int> BehindDirection(pair<int, int> here, int direction) {
	int hereX = here.second;
	int hereY = here.first;
	switch (direction) {
	case 0:
		return make_pair(hereY + 1, hereX);
	case 1:
		return make_pair(hereY, hereX - 1);
	case 2:
		return make_pair(hereY - 1, hereX);
	case 3:
		return make_pair(hereY, hereX + 1);
	}

	return make_pair(hereY, hereX);
}

bool FourDirectionIsWallOrClean(pair<int, int> here, vector<vector<int> >&scope,
		vector<vector<bool> >&visited) {
	int hereX = here.second;
	int hereY = here.first;

	if (scope[hereY + 1][hereX] == 1 || visited[hereY + 1][hereX]) {
		if (scope[hereY - 1][hereX] == 1 || visited[hereY - 1][hereX]) {
			if (scope[hereY][hereX + 1] == 1 || visited[hereY][hereX + 1]) {
				if (scope[hereY][hereX - 1] == 1 || visited[hereY][hereX - 1]) {
					return true;
				} else
					return false;
			} else
				return false;
		} else
			return false;
	} else
		return false;
}
void dfs(pair<int, int> here, vector<vector<int> >&scope,
		vector<vector<bool> >&visited, int direction) {
	int hereX = here.second;
	int hereY = here.first;

	//1. 현재 위치를 청소한다.
	visited[hereY][hereX] = true;

	pair<int, int> there = NextDirection(here, direction);
	int thereX = there.second;
	int thereY = there.first;
	//2. 현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
	//1) 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면
	if (scope[thereY][thereX] == 0 && !visited[thereY][thereX]) {
		//그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
		if (direction == 0)
			direction = 3;
		else
			direction = direction - 1;

		dfs(make_pair(thereY, thereX), scope, visited, direction);
	}
	//3, 4) 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는
	else if (FourDirectionIsWallOrClean(here, scope, visited)) {
		pair<int, int> behind = BehindDirection(here, direction);
		int behindX = behind.second;
		int behindY = behind.first;
		//뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
		if (scope[behindY][behindX] == 1) {
			return;
		}
		// 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
		else {
			dfs(make_pair(behindY, behindX), scope, visited, direction);
		}
	}
	//2) 왼쪽 방향에 청소할 방향이 없다면
	else {
		//그 방향으로 회전하고 2번으로 돌아간다.
		if (direction == 0)
			direction = 3;
		else
			direction = direction - 1;
		dfs(make_pair(hereY, hereX), scope, visited, direction);
	}
}
int main() {
	int N, M;
	cin >> N >> M;

	int r, c, d;
	cin >> r >> c >> d;

	vector<vector<int> > scope(N, vector<int>(M, 0));
	vector<vector<bool> > visited(N, vector<bool>(M, false));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> scope[i][j];
		}
	}

	dfs(make_pair(r, c), scope, visited, d);

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == true) {
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
